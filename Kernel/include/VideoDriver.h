//
//  VideoDriver.h
//  
//
//  Created by Fermin Gomez on 5/23/18.
//
//
#include <stdint.h>
#ifndef VideoDriver_h
#define VideoDriver_h

#include <stdio.h>

	typedef struct {
		uint8_t Red;
		uint8_t Green;
		uint8_t Blue;
	} Colour;


	void putPixel(int x, int y, Colour color);
    void putStr(char * str, Colour colour);
    void putChar(char c, Colour colour);
	int RGBColourToInt(Colour colour);

#endif /* VideoDriver_h */
