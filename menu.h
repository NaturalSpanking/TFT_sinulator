#ifndef _MENU_H_
#define _MENU_H_

#include <stdint.h>

typedef enum{
	kbdUP, kbdDOWN, kbdLEFT, kbdRIGHT, kbdM, kbdC, kbdF, kbdLIGHT, kbdPOWER
}KBD_Buttons;

void FSM_MenuInit();
void FSM_MenuProcess();

extern KBD_Buttons PressedKey;

#endif
