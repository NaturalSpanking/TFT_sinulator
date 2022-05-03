
#include <windows.h>
#include "primitives.h"

extern HDC window_dc;

#define SPACE 2

typedef struct {
	uint16_t height;
	uint16_t width;
	void* data;
} TBitmapText;

static TBitmapText* MakeTextBitmap(const char *text, const FontGLCD_t* font,
		EColor text_color, EColor bg_color, uint8_t extra_space);
static TBitmapText* MakeTextBitmap2(const char *text, const PFont font, EColor color,
		EColor bg_color, uint8_t extra_space) ;
static void FreeTextBitmap(TBitmapText* bitmap);

static COLORREF RGB565_to_RGB888(uint16_t rgb565){
	uint8_t r,g,b;
	r = (((rgb565>>(5+6))&0b11111)<<3)|0b111;
	g = (((rgb565>>(5))&0b111111)<<2)|0b11;
	b = ((rgb565&0b11111)<<3)|0b111;
	return RGB(r,g,b);
}

void TFT_DrawFillRect(int x,int y, int width, int height, EColor color){
	for(int j=y;j<y+height;j++){
		for(int i=x;i<x+width;i++){
			SetPixel(window_dc,i,j,RGB565_to_RGB888(color));
		}
	}
}

void TFT_DrawHLine(int x, int y, int Len, EColor color){
	for(int i = 0; i<Len;i++){
		SetPixel(window_dc,x+i,y,RGB565_to_RGB888(color));
	}
}

void TFT_DrawVLine(int x, int y, int Len, EColor color){
	for(int i = 0; i<Len;i++){
		SetPixel(window_dc,x,y+i,RGB565_to_RGB888(color));
	}
}

uint16_t TFT_DrawText(int x, int y, const char* str, const FontGLCD_t* font, EColor color, EColor bg_color, uint8_t extra_space){
	TBitmapText* bmp;
	bmp=MakeTextBitmap(str,font,color,bg_color,2);
	int idx=0;
	uint16_t* dat;
	dat = (uint16_t*)bmp->data;
	for(int j=y;j<y+bmp->height;j++){
		for(int i=x;i<x+bmp->width;i++){
			SetPixel(window_dc,i,j,RGB565_to_RGB888(dat[idx++]));
		}
	}
	uint16_t ret = bmp->width;
	FreeTextBitmap(bmp);
	return ret;
}

uint16_t TFT_DrawText2(int x, int y, const char* str, const PFont font, EColor color, EColor bg_color, uint8_t extra_space){
	TBitmapText* bmp;
	bmp=MakeTextBitmap2(str,font,color,bg_color,2);
	int idx=0;
	uint16_t* dat;
	dat = (uint16_t*)bmp->data;
	for(int j=y;j<y+bmp->height;j++){
		for(int i=x;i<x+bmp->width;i++){
			SetPixel(window_dc,i,j,RGB565_to_RGB888(dat[idx++]));
		}
	}
	uint16_t ret = bmp->width;
	FreeTextBitmap(bmp);
	return ret;
}

TBitmapText* MakeTextBitmap(const char *text, const FontGLCD_t* font, EColor color,
		EColor bg_color, uint8_t extra_space) {
	TBitmapText* ret = malloc(sizeof(TBitmapText));

	int bytes_per_column = font->FontHeight / 8 // ��� ���������� ���� �� ������� ����������� � ���������� ������
			+ (font->FontHeight % 8 ? 1 : 0); // ���������� ���� �� 1 ������� �������
	int bytes_per_char = font->FontWidth * bytes_per_column + 1; // ���������� ���� �� ������
	int char_index;							// ������ ������� � ������� ������
	const uint8_t* chars_table;				// ������� ��������, � ������ �� ���
	ret->height = font->FontHeight;
	ret->width = 0;
	for (int i = 0; text[i]; i++) { // ������ �� ������ � ���������� ������ �������
		if ((uint8_t)text[i] >= font->FirstCharRU) {		//�������� �����
				chars_table = font->data_ru;
				char_index = ((uint8_t)text[i] - font->FirstCharRU) * bytes_per_char;// ������ ������� � ������� �������
			} else {
				chars_table = font->data_regular;
				char_index = ((uint8_t)text[i] - font->FirstChar) * bytes_per_char;	// ������ ������� � ������� �������
			}
		ret->width += (font->isMono ?font->FontWidth+extra_space :chars_table[char_index] + extra_space);
	}
	/*
	 * ��������� ����������� ������ �� ��������, ������ ��� �������� � ���� ������ ���������� � ������� ������ ������ ��� ���,
	 * uint8_t **buf = malloc(buf_size + sizeof(uint8_t*)* ret.height); // ����� �������
	 * for(int i = 0; i<ret.height;i++){
	 *	buf[i] = (uint8_t*)buf +ret.height+ i*ret.width;
	 *	}
	 *	*(*(buf+i)+j) = 0xAC; ���������� buf[i][j] =
	 *
	 * */
	uint16_t *buf = malloc(ret->height * ret->width * sizeof(uint16_t)); // ��������� ������ ��� �������

	for (int i = 0; i < ret->height; i++) {
		for (int j = 0; j < ret->width; j++) {
			buf[i * ret->width + j] = 0xAC35; // �������� ������ �� ����
		}
	}

	ret->data = buf;
	int stolb_idx = 0;
	for (int simv = 0; text[simv]; simv++) { // ������ �� ��������
		if ((uint8_t)text[simv] >= font->FirstCharRU) {		//�������� �����
						chars_table = font->data_ru;
						char_index = ((uint8_t)text[simv] - font->FirstCharRU) * bytes_per_char;// ������ ������� � ������� �������
					} else {
						chars_table = font->data_regular;
						char_index = ((uint8_t)text[simv] - font->FirstChar) * bytes_per_char;	// ������ ������� � ������� �������
					}
		int col_index = char_index + 1; // ������ ������� ������� ������� � ������� ������, �������� bytes_per_column
		int char_width = font->isMono ?	font->FontWidth : chars_table[char_index];
		for (int stolb = 0;	stolb < char_width; stolb++) { // ������ �� ��������
			for (int bait = 0; bait < bytes_per_column; bait++) { // ������ �� ������ �������
				int x = chars_table[col_index + bait]; // ����, ������� ����� ������ ����������
				int bit_count = font->FontHeight - bait * 8 >= 8 ? 8 : font->FontHeight % 8; // ���-�� ������������ ���
				for (int bit = 0; bit < bit_count; bit++) {	// ������ �� �����
					uint32_t buf_idx = 	bit * ret->width +
										bait * 8 * ret->width +
										stolb_idx +
										stolb;
					buf[buf_idx] = (x & 0b1) ? color : bg_color;
					x >>= 1;
				}
			}
			col_index += bytes_per_column;
		}
		stolb_idx += char_width;
		for (int stolb = 0; stolb < extra_space; stolb++) {// �������������� ������������ ����� ���������
					for (int stroka = 0; stroka < font->FontHeight; stroka++) { // ������ �� ������ �������
							uint32_t buf_idx =	stroka * ret->width +
												stolb_idx +
												stolb;
							buf[buf_idx] = bg_color;	//0xad;
					}
				}
		stolb_idx += extra_space;
	}
	return ret;
}

TBitmapText* MakeTextBitmap2(const char *text, const PFont font, EColor color,
		EColor bg_color, uint8_t extra_space) {
	TBitmapText* ret = malloc(sizeof(TBitmapText));

//	int bytes_per_column = font->FontHeight / 8 // ��� ���������� ���� �� ������� ����������� � ���������� ������
//			+ (font->FontHeight % 8 ? 1 : 0); // ���������� ���� �� 1 ������� �������
//	int bytes_per_char = font->FontWidth * bytes_per_column + 1; // ���������� ���� �� ������

	int chart = 0;							// ����� ������� ��������
	int char_index;							// ������ ������� � ������� ������
	const TFontTable* table;				// ������� ��������, � ������ �� �����

	ret->height = font->Height;
	ret->width = 0;
	for (int i = 0; text[i]; i++) { // ������ �� ������ � ���������� ������ �������
		if((uint8_t)text[i]<9){ // ������ ������ �������
			chart = (uint8_t)text[i]-1;
			continue;
		}
		if (chart>1){
			table = font->Tables[chart];
		}else{
			if ((uint8_t)text[i] >= font->Tables[1]->FirstChar) {	//�������� �����
				table = font->Tables[1];
			} else {
				table = font->Tables[0];
			}
		}
		char_index = (uint8_t)text[i] - table->FirstChar;// ������ ������� � ������� �������
		ret->width += table->Chars[char_index][0] + extra_space;
	}
	/*
	 * ��������� ����������� ������ �� ��������, ������ ��� �������� � ���� ������ ���������� � ������� ������ ������ ��� ���,
	 * uint8_t **buf = malloc(buf_size + sizeof(uint8_t*)* ret.height); // ����� �������
	 * for(int i = 0; i<ret.height;i++){
	 *	buf[i] = (uint8_t*)buf +ret.height+ i*ret.width;
	 *	}
	 *	*(*(buf+i)+j) = 0xAC; ���������� buf[i][j] =
	 *
	 * */
	uint16_t *buf = malloc(ret->height * ret->width * sizeof(uint16_t)); // ��������� ������ ��� �������

	for (int i = 0; i < ret->height; i++) {
		for (int j = 0; j < ret->width; j++) {
			buf[i * ret->width + j] = 0xAC35; // �������� ������ �� ����
		}
	}

	ret->data = buf;
	chart = 0;
	int stolb_idx = 0;
	for (int simv = 0; text[simv]; simv++) { // ������ �� ��������

		if((uint8_t)text[simv]<9){ // ������ ������ �������
					chart = (uint8_t)text[simv]-1;
					continue;
				}
				if (chart>1){
					table = font->Tables[chart];
				}else{
					if ((uint8_t)text[simv] >= font->Tables[1]->FirstChar) {	//�������� �����
						table = font->Tables[1];
					} else {
						table = font->Tables[0];
					}
				}
				char_index = (uint8_t)text[simv] - table->FirstChar;// ������ ������� � ������� �������


		int col_index = 1; // ������ ������� ������� ������� � ������� ������, �������� bytes_per_column
		int char_width = table->Chars[char_index][0];

		for (int stolb = 0;	stolb < char_width; stolb++) { // ������ �� ��������
			for (int bait = 0; bait < font->BPC; bait++) { // ������ �� ������ �������
				int x = table->Chars[char_index][col_index + bait]; // ����, ������� ����� ������ ����������
				int bit_count = font->Height - bait * 8 >= 8 ? 8 : font->Height % 8; // ���-�� ������������ ���
				for (int bit = 0; bit < bit_count; bit++) {	// ������ �� �����
					uint32_t buf_idx = 	bit * ret->width +
										bait * 8 * ret->width +
										stolb_idx +
										stolb;
					buf[buf_idx] = (x & 0b1) ? color : bg_color;
					x >>= 1;
				}
			}
			col_index += font->BPC;
		}
		stolb_idx += char_width;
		for (int stolb = 0; stolb < extra_space; stolb++) {// �������������� ������������ ����� ���������
					for (int stroka = 0; stroka < font->Height; stroka++) { // ������ �� ������ �������
							uint32_t buf_idx =	stroka * ret->width +
												stolb_idx +
												stolb;
							buf[buf_idx] = bg_color;	//0xad;
					}
				}
		stolb_idx += extra_space;
	}
	return ret;
}

void FreeTextBitmap(TBitmapText* bitmap) {
	free(bitmap->data);
	free(bitmap);
}
