/*
 * Уровнь графических примитивов. Идет поверх уровня драйвера дисплея.
 */

#ifndef _PRIMITIVES_H
#define _PRIMITIVES_H

#include <stdint.h>
#include "fonts_GLCD.h"
#include "NS_fonts.h"

#define TFT_W 320
#define TFT_H 240

typedef enum _EColor {
	clBlack = 0x0000, clWhite = 0xFFFF, clBlue = 0x001F, clUltra = 0x67FD
} EColor;

void TFT_DrawVLine(int x, int y, int Len, EColor color);
void TFT_DrawHLine(int x, int y, int Len, EColor color);
uint16_t TFT_DrawText(int x, int y, const char* str, const FontGLCD_t* font, EColor color, EColor bg_color, uint8_t extra_space);
uint16_t TFT_DrawText2(int x, int y, const char* str, const PFont font, EColor color, EColor bg_color, uint8_t extra_space);
void TFT_DrawFillRect(int x,int y, int width, int height, EColor color);

#endif //_PRIMITIVES_H
