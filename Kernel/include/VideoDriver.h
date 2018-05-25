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
	void putHexa( uint64_t number, Colour colour);
	static uint64_t uintToBase(uint64_t value, char * buffer, uint64_t base);
	void printBase(uint64_t value, uint64_t base, Colour colour);

#endif /* VideoDriver_h */
