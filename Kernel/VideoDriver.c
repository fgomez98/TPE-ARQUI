//
//  VideoDriver.c
//
//
//  Created by Fermin Gomez on 5/23/18.
//
//
#include "VideoDriver.h"
#include "font.h"
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 16
#define Y_SPACE 2// espacio entre lineas
#define X_SPACE 1// espacio entre caracteres
static char buffer[64] = { '0' }; // esto es para imprimir hexa

typedef struct __attribute__((packed)) ModeInfoBlock {
        uint16_t ModeAttributes;
        uint8_t WinAAttributes;
        uint8_t WinBAttributes;
        uint16_t WinGranularity;
        uint16_t WinSize;
        uint16_t WinSegmentA;
        uint16_t WinSegmentB;
        uint32_t WinRealFctPtr;
        uint16_t pitch; // Bytes per ScanLine.

        uint16_t XResolution;
        uint16_t YResolution;
        uint8_t XcharSize;
        uint8_t YcharSize;
        uint8_t NumberOfPlanes;
        uint8_t BitsPerPixel;
        uint8_t NumberOfBanks;
        uint8_t MemoryModel;
        uint8_t BankSize;
        uint8_t NumberOfImagePages;
        uint8_t ReservedPage;

        uint8_t RedMaskSize;
        uint8_t RedMaskPosition;
        uint8_t GreenMaskSize;
        uint8_t GreenMaskPosition;
        uint8_t BlueMaskSize;
        uint8_t BlueMaskPosition;
        uint8_t ReservedMaskSize;
        uint8_t ReservedMaskPosition;
        uint8_t DirectColorAttributes;

        uint32_t PhysBasePtr;  // Your LFB (Linear Framebuffer) address.
        uint32_t OffScreenMemOffset;
        uint16_t OffScreenMemSize;
} Vesa;

static Vesa * video = (Vesa*)0x5C00;
static int XPOSITION = 5;
static int YPOSITION = 5;

void memCpy(void *dest, void *src, size_t n) { // tendria que guardarla en otro lado
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
    for (int i=0; i<n; i++) {
        cdest[i] = csrc[i];
    }
}

void putPixel(int x, int y, Colour colour) {
	unsigned whereOnScreen = y*video->pitch + x*(video->BitsPerPixel/8);
	char * screen = (char *) (video->PhysBasePtr + whereOnScreen);
	*(screen) = colour.Red;
	*(screen + 1) = colour.Green;
	*(screen +2) = colour.Blue;
}

void printChar(char c, Colour colour) {
    char font;
    char *  font_char = pixel_map(c);
    for (int y = 0; y < 16; y++) {
        char font = font_char[y];
        for (int x = 0; x < 8; x++) {
            if (((font >> 8-x) %2) != 0){
                putPixel(x + XPOSITION, y + YPOSITION, colour);
            } else {
                Colour colourBlank = {0, 0, 0};
                putPixel(x + XPOSITION, y + YPOSITION, colourBlank);
            }
        }
    }
}

int RGBColourToInt(Colour colour) {
  int c = colour.Red;
  c = (c << 8) | colour.Green;
  c = (c << 8) | colour.Blue;
  return c;
}

void putChar(char c, Colour colour) {
    boundaryCorrector();
    printChar(c, colour);
    XPOSITION += 9;
    boundaryCorrector();
}

void putStr(char * str, Colour colour) { // lee hasta el barra cero, si no lo tiene como hago para que corte en algun momento (excepcion)
    char c;
    int i = 0;
    while ( (c = str[i++]) != '\0') {
        putChar(c, colour);
    }
}




void newLine() {
    YPOSITION += 16;
    XPOSITION = 5;
    // chequear que no se vaya de la pantalla y
}

void boundaryCorrector() {
    if (video->XResolution < XPOSITION || ((video->XResolution - XPOSITION) < 8)) {
        newLine();
    } else if (video->YResolution <= YPOSITION) {
        // que hago??
    }
}

void moveScreenUp() {
    unsigned whereOnScreen = (16+Y_SPACE)*(video->pitch);
    char * source = (char *) (video->PhysBasePtr + whereOnScreen);
    char * dest = (char *) (video->PhysBasePtr);
    int size = ((video->YResolution)-16-Y_SPACE)*(video->XResolution);
    memCpy(dest, source, size);
    for (int y = video->YResolution - 2*(16+Y_SPACE) ; y < video->YResolution -16; y ++) {
        for (int x = 0; x < video->XResolution; x++) {
            Colour colourBlank = {0, 0, 0};
            putPixel(x, y , colourBlank);
        }
    }

}












//pasar de uint64_t a hexa y de ahi imprmir en pantalla
void putHexa( uint64_t value, Colour colour){
  	printBase(value, 16, colour);
}

void printBase(uint64_t value, uint64_t base, Colour colour)
{
    uintToBase(value, buffer, base);
    putStr(buffer, colour);
}

static uint64_t uintToBase(uint64_t value, char * buffer, uint64_t base)
{
	char *p = buffer;
	char *p1, *p2;
	uint64_t digits = 0;

	//Calculate characters for each digit
	do
	{
		uint64_t remainder = value % base;
		*p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
		digits++;
	}
	while (value /= base);

	// Terminate string in buffer.
	*p = 0;

	//Reverse string in buffer.
	p1 = buffer;
	p2 = p - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}

	return digits;
}
