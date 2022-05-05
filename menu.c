#include "menu.h"
#include "tree_menu.h"
#include "objects.h"
#include <stdio.h>

#define TM_MENU_SIZE 66
const TM_Unit menu[TM_MENU_SIZE]={
  {-1, false, "��\x03""23\x1�", 0, 0, 0, 0},
    {0, false, "���", 0, 0, 0, 0},
      {1, true, "��������", 0, 4095, 1, 1000},
      {1, true, "���", 0, 3, 1, 1},
    {0, false, "�������", 0, 0, 0, 0},
      {4, true, "��������", 0, 4095, 1, 1000},
      {4, true, "���", 0, 4095, 1, 1000},
    {0, false, "�������", 0, 0, 0, 0},
      {7, true, "���� 1", 0, 4095, 1, 1000},
      {7, true, "���� 2", 0, 4095, 1, 1000},
      {7, true, "���", 0, 1, 1, 1},
    {0, false, "����", 0, 0, 0, 0},
      {11, true, "�����", 0, 3, 1, 1},
      {11, true, "���", 40, 250, 1, 10},
      {11, false, "����� 1", 0, 0, 0, 0},
        {14, true, "����1", 0, 4095, 1, 1000},
        {14, true, "���1", 0, 4095, 1, 1000},
        {14, true, "�����1", 0, 4095, 1, 1000},
      {11, false, "����� 2", 0, 0, 0, 0},
        {18, true, "����2", 0, 4095, 1, 1000},
        {18, true, "���2", 0, 4095, 1, 1000},
        {18, true, "�����2", 0, 4095, 1, 1000},
      {11, false, "����� 3", 0, 0, 0, 0},
        {22, true, "����3", 0, 4095, 1, 1000},
        {22, true, "���3", 0, 4095, 1, 1000},
        {22, true, "�����3", 0, 4095, 1, 1000},
  {-1, false, "SI5351", 0, 0, 0, 0},
    {26, true, "�������", 500000, 2350000, 100, 1000000},
    {26, false, "���", 0, 0, 0, 0},
      {28, true, "�����0", 0, 1, 1, 1},
      {28, true, "�����1", 0, 1, 1, 1},
      {28, true, "�����2", 0, 1, 1, 1},
    {26, true, "��������", 0, 3, 1, 1},
  {-1, false, "ADS1115", 0, 0, 0, 0},
    {33, false, "watch01", 0, 0, 0, 0},
    {33, false, "watch23", 0, 0, 0, 0},
    {33, true, "HI_t", 1, 32767, 1, 10000},
    {33, true, "LO_t", 1, 32767, 1, 10000},
    {33, true, "���", 0, 1, 1, 1},
    {33, true, "gain", 0, 5, 1, 1},
    {33, true, "Menu44", 0, 100, 1, 100},
    {33, true, "Menu45", 0, 100, 1, 100},
    {33, true, "Menu46", 0, 100, 1, 100},
    {33, true, "Menu47", 0, 100, 1, 100},
    {33, true, "Menu48", 0, 100, 1, 100},
    {33, true, "Menu49", 0, 100, 1, 100},
    {33, true, "Menu50", 0, 100, 1, 100},
    {33, true, "Menu51", 0, 100, 1, 100},
    {33, true, "Menu52", 0, 100, 1, 100},
    {33, true, "Menu53", 0, 100, 1, 100},
  {-1, true, "RFM_sign", 32, 83, 1, 1},
  {-1, false, "Menu41", 0, 100, 1, 100},
    {51, false, "Menu54", 0, 100, 1, 100},
      {52, false, "Menu58", 0, 100, 1, 100},
        {53, false, "Menu60", 0, 100, 1, 100},
          {54, false, "Menu62", 0, 100, 1, 100},
            {55, true, "Menu64", 0, 100, 1, 100},
            {55, true, "Menu65", 0, 100, 1, 100},
          {54, true, "Menu63", 0, 100, 1, 100},
        {53, true, "Menu61", 0, 100, 1, 100},
      {52, true, "Menu59", 0, 100, 1, 100},
    {51, true, "Menu55", 0, 100, 1, 100},
  {-1, false, "Menu42", 0, 100, 1, 100},
    {62, true, "Menu56", 0, 100, 1, 100},
    {62, true, "Menu57", 0, 100, 1, 100},
  {-1, true, "Menu43", 0, 100, 1, 100}
};

TM_Param params[TM_MENU_SIZE]={
  {0, 0},{0, 0},{2048, 10},{0, 1},{0, 0},
  {2048, 10},{2048, 10},{0, 0},{2048, 10},{2048, 10},
  {0, 1},{0, 0},{0, 1},{140, 10},{0, 0},
  {2878, 10},{10, 10},{3215, 10},{0, 0},{718, 10},
  {0, 10},{785, 10},{0, 0},{248, 10},{0, 10},
  {260, 10},{0, 0},{1500000, 1000},{0, 0},{0, 1},
  {0, 1},{0, 1},{0, 1},{0, 0},{0, 0},
  {0, 0},{15000, 10},{13000, 10},{0, 1},{0, 1},
  {0, 10},{0, 10},{0, 10},{0, 10},{0, 10},
  {0, 10},{0, 10},{0, 10},{0, 10},{0, 10},
  {32, 1},{0, 10},{0, 10},{0, 10},{0, 10},
  {0, 10},{0, 10},{0, 10},{0, 10},{0, 10},
  {0, 10},{0, 10},{0, 10},{0, 10},{0, 10},
  {0, 10}
};

void PrintMenu(int index, TM_DeepLevel DeepLevel);
void ChangeParam(int index);

TM_Config main_cfg;
KBD_Buttons PressedKey;
int LastItem;

void FSM_MenuInit() {
	main_cfg.MenuSize = TM_MENU_SIZE;
	main_cfg.Menus = menu;
	main_cfg.Params = params;
	main_cfg.PrintCallback = PrintMenu;
	main_cfg.ChangeCallback = ChangeParam;
	InitMenu(&main_cfg);
	PressedKey = -1;
	LastItem = 1; // �������� ����� �����, ���� � ������ ��� �������������� �������� ��������� ����. id �������� != -1
	PrintMenu(0,DL_NAME);
}

void FSM_MenuProcess() {
	switch (PressedKey) {
	case kbdUP:
		//TFT_DrawText(100,100,"qwewas",&ISOCPEUR19x35,clBlack,clWhite,2);
		JumpMenu(MD_LEFT);
		break;
	case kbdDOWN:
		//TFT_DrawFillRect(100,100,100,50,clWhite);
		JumpMenu(MD_RIGHT);
		break;
	case kbdLEFT:
		//TFT_DrawHLine(10,10,100,clBlack);
		break;
	case kbdRIGHT:
		//TFT_DrawVLine(10,10,100,clBlack);
		break;
	case kbdF:
		JumpMenu(MD_DOWN);
		break;
	case kbdC:
		JumpMenu(MD_UP);
		break;

	};
	if (PressedKey != -1)
		PressedKey = -1;
}

void PrintItem(int arr_idx, int Position, int selected) {
//	TFT_DrawText(10, 26 + 26 + 2 + 2 + 26 * Position, menu[arr_idx].name,
//			&Courier_New_Bold16x26, clBlack, (selected) ? clUltra : clWhite, 1);
	TFT_DrawText2(10, 26 + 26 + 2 + 2 + 26 * Position, menu[arr_idx].name,
			Times_New_Roman_Regular_30, clBlack, (selected) ? clUltra : clWhite, 1);
}

void PrintPage(int index) {
	static int LSP; // last select pos
	if (menu[LastItem].parent_id != menu[index].parent_id) {// ����� ������
		TFT_DrawFillRect(0, 26, 320, 240 - 26, clWhite); // ������ �����������
		OBJ_DrawMenuLabel(
				menu[index].parent_id == -1 ?
						"������� ����" : menu[menu[index].parent_id].name);

		int X = 0; // ����� ������ �� �������
		for (int i = 0; i < TM_MENU_SIZE; i++) {
			if (menu[i].parent_id == menu[index].parent_id) {
				PrintItem(i,X,index==i);
				if(i==index)LSP=X;
				X++;
			}
		}
	} else {
		PrintItem(LastItem,LSP,0);
		int X = 0; // ����������  ������� � ���� �������
		for (int i = 0; i < TM_MENU_SIZE; i++) {
			if (menu[i].parent_id == menu[index].parent_id) {
				if (i == index) {
					PrintItem(i,X,1);
					LSP = X;
				}
				X++;
			}
		}
	}
	LastItem = index;

}

void PrintEdit(int index){
	char tmp[20];
	sprintf(tmp,"%d",params[index].value);
	TFT_DrawText(150,200,tmp,&Courier_New_Bold16x26,clBlack,clWhite,1);
	sprintf(tmp,"%d",params[index].delta);
	TFT_DrawText(150,170,tmp,&Courier_New_Bold16x26,clBlack,clWhite,1);
}

void PrintMenu(int index, TM_DeepLevel DeepLevel) {
// printing function prototype
	switch (DeepLevel) {
	case DL_NAME: // print name
		PrintPage(index);
		break;
	case DL_DELTA: // print param with cursor on symbol which will be change
		PrintEdit(index);
		break;
	case DL_PARAM: // print param with cursor on symbol which changing

		break;
	}
}

void ChangeParam(int index){
  // change parameter function prototype
  switch(index){
    case 2: // ��������

    break; // end of ��������
    case 3: // ���

    break; // end of ���
    case 5: // ��������

    break; // end of ��������
    case 6: // ���

    break; // end of ���
    case 8: // ���� 1

    break; // end of ���� 1
    case 9: // ���� 2

    break; // end of ���� 2
    case 10: // ���

    break; // end of ���
    case 12: // �����

    break; // end of �����
    case 13: // ���

    break; // end of ���
    case 15: // ����1

    break; // end of ����1
    case 16: // ���1

    break; // end of ���1
    case 17: // �����1

    break; // end of �����1
    case 19: // ����2

    break; // end of ����2
    case 20: // ���2

    break; // end of ���2
    case 21: // �����2

    break; // end of �����2
    case 23: // ����3

    break; // end of ����3
    case 24: // ���3

    break; // end of ���3
    case 25: // �����3

    break; // end of �����3
    case 27: // �������

    break; // end of �������
    case 29: // �����0

    break; // end of �����0
    case 30: // �����1

    break; // end of �����1
    case 31: // �����2

    break; // end of �����2
    case 32: // ��������

    break; // end of ��������
    case 36: // HI_t

    break; // end of HI_t
    case 37: // LO_t

    break; // end of LO_t
    case 38: // ���

    break; // end of ���
    case 39: // gain

    break; // end of gain
    case 40: // Menu44

    break; // end of Menu44
    case 41: // Menu45

    break; // end of Menu45
    case 42: // Menu46

    break; // end of Menu46
    case 43: // Menu47

    break; // end of Menu47
    case 44: // Menu48

    break; // end of Menu48
    case 45: // Menu49

    break; // end of Menu49
    case 46: // Menu50

    break; // end of Menu50
    case 47: // Menu51

    break; // end of Menu51
    case 48: // Menu52

    break; // end of Menu52
    case 49: // Menu53

    break; // end of Menu53
    case 50: // RFM_sign

    break; // end of RFM_sign
    case 56: // Menu64

    break; // end of Menu64
    case 57: // Menu65

    break; // end of Menu65
    case 58: // Menu63

    break; // end of Menu63
    case 59: // Menu61

    break; // end of Menu61
    case 60: // Menu59

    break; // end of Menu59
    case 61: // Menu55

    break; // end of Menu55
    case 63: // Menu56

    break; // end of Menu56
    case 64: // Menu57

    break; // end of Menu57
    case 65: // Menu43

    break; // end of Menu43
    default:
    break;
  }
}

void ExecuteCmd(int index){
  // �ommand execution function prototype
  switch(index){
    case 34: // watch01

    break; // end of watch01
    case 35: // watch23

    break; // end of watch23
    default:
    break;
  }
}
void SpecFunction(int index){
  // special function prototype
  switch(index){
    case 2: // ��������

    break; // end of ��������
    case 3: // ���

    break; // end of ���
    case 5: // ��������

    break; // end of ��������
    case 6: // ���

    break; // end of ���
    case 8: // ���� 1

    break; // end of ���� 1
    case 9: // ���� 2

    break; // end of ���� 2
    case 10: // ���

    break; // end of ���
    case 12: // �����

    break; // end of �����
    case 13: // ���

    break; // end of ���
    case 15: // ����1

    break; // end of ����1
    case 16: // ���1

    break; // end of ���1
    case 17: // �����1

    break; // end of �����1
    case 19: // ����2

    break; // end of ����2
    case 20: // ���2

    break; // end of ���2
    case 21: // �����2

    break; // end of �����2
    case 23: // ����3

    break; // end of ����3
    case 24: // ���3

    break; // end of ���3
    case 25: // �����3

    break; // end of �����3
    case 27: // �������

    break; // end of �������
    case 29: // �����0

    break; // end of �����0
    case 30: // �����1

    break; // end of �����1
    case 31: // �����2

    break; // end of �����2
    case 32: // ��������

    break; // end of ��������
    case 34: // watch01

    break; // end of watch01
    case 35: // watch23

    break; // end of watch23
    case 36: // HI_t

    break; // end of HI_t
    case 37: // LO_t

    break; // end of LO_t
    case 38: // ���

    break; // end of ���
    case 39: // gain

    break; // end of gain
    case 40: // Menu44

    break; // end of Menu44
    case 41: // Menu45

    break; // end of Menu45
    case 42: // Menu46

    break; // end of Menu46
    case 43: // Menu47

    break; // end of Menu47
    case 44: // Menu48

    break; // end of Menu48
    case 45: // Menu49

    break; // end of Menu49
    case 46: // Menu50

    break; // end of Menu50
    case 47: // Menu51

    break; // end of Menu51
    case 48: // Menu52

    break; // end of Menu52
    case 49: // Menu53

    break; // end of Menu53
    case 50: // RFM_sign

    break; // end of RFM_sign
    case 56: // Menu64

    break; // end of Menu64
    case 57: // Menu65

    break; // end of Menu65
    case 58: // Menu63

    break; // end of Menu63
    case 59: // Menu61

    break; // end of Menu61
    case 60: // Menu59

    break; // end of Menu59
    case 61: // Menu55

    break; // end of Menu55
    case 63: // Menu56

    break; // end of Menu56
    case 64: // Menu57

    break; // end of Menu57
    case 65: // Menu43

    break; // end of Menu43
    default:
    break;
  }
}

