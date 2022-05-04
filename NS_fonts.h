/*
 * NS_fonts.h
 *
 *  Created on: 4 мая 2022 г.
 *      Author: CaHuTaP
 */

#ifndef NS_FONTS_H_
#define NS_FONTS_H_

typedef struct {
	unsigned char FirstChar;
	const unsigned char *Chars[];
} TFontTable;

typedef struct {
	unsigned char Height;
	unsigned char Width;
	unsigned char BPC; // bytes per column
	const TFontTable *Tables[];
} TFont;

typedef const TFont *PFont;



extern const PFont Times_New_Roman_Regular_16;

#endif /* NS_FONTS_H_ */
