#include "objects.h"

void OBJ_DrawStausBar() {
	TFT_DrawFillRect(0, 0, TFT_W, STATUS_BAR_H, clBlue);
}

void OBJ_DrawMenuLabel(const char* Str) {
	TFT_DrawFillRect(0,STATUS_BAR_H + 2,320,26,clWhite);
	TFT_DrawText(10, STATUS_BAR_H + 2, Str, &Courier_New_Bold16x26, clBlack,
			clWhite, 1);
	TFT_DrawHLine(80,STATUS_BAR_H + 2+26,320-160,clBlue);
}
