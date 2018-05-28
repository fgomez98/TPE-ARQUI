//
//  VideoDriver.c
//
//
//  Created by Fermin Gomez on 5/23/18.
//
//
#include "VideoDriver.h"
#include "font.h"
#include "lib.h"
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 16
static char buffer[64] = { '0' }; // esto es para imprimir hexa
#define Y_SPACE 2// espacio entre lineas
#define X_SPACE 1// espacio entre caracteres

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

Colour black = {0, 0, 0};
Colour white = {255, 255, 255};
static Vesa * video = (Vesa*)0x5C00;
static int XPOSITION = X_SPACE;
static int YPOSITION = Y_SPACE;
static int XPOSITION2 = X_SPACE;
static int YPOSITION2 = Y_SPACE;


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
        font = font_char[y];
        for (int x = 0; x < 8; x++) {
            if (((font >> 8-x) %2) != 0){
                putPixel(x + XPOSITION, y + YPOSITION, colour);
            } else {
                putPixel(x + XPOSITION, y + YPOSITION, black);
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

// imprime un caracter en pantalla
void putChar(char c, Colour colour) {
    boundaryCorrector();
    printChar(c, colour);
    XPOSITION += CHAR_WIDTH + X_SPACE;
    boundaryCorrector();
}

void putStrAux(char * str, Colour colour) {
    int i = strlen(str);
    if ((XPOSITION+(CHAR_WIDTH+X_SPACE)*i) > video->XResolution) {
        newLine();
    }
    char c;
    i = 0;
    while ( (c = str[i++])) {
        putChar(c, colour);
    }
}

// imprime un string en pantalla
void putStr(char * str, Colour colour) { // lee hasta el cero, si no lo tiene como hago para que corte en algun momento (excepcion)
    
    char buff[24] = {0};
    char c;
    int i = 0;
    int j = 0;
    while ((c=str[i++])) {

        buff[j++] = c;
        if (c == ' ') {
            buff[j] = 0;
            putStrAux(buff, colour);
            memSet(buff, 0, j);
            j = 0;
        } else if (c == '\n') {
            newLine();
        }
    }
    if (c == 0) {
        putStrAux(buff, colour);
    }
}

void newLine() {
    YPOSITION += 16 + Y_SPACE;
    XPOSITION = X_SPACE;
    boundaryCorrector();
}

void boundaryCorrector() {
    if (video->XResolution < XPOSITION || ((video->XResolution - XPOSITION) < 8)) {
        newLine();
    } else if ((video->YResolution -Y_SPACE - CHAR_HEIGHT) <= YPOSITION) {
        YPOSITION -= CHAR_HEIGHT -Y_SPACE;
        moveScreenUp();
    }
}

//corre las lineas hacia arriba excluyendo la ultima
void moveScreenUp() {
    unsigned whereOnScreen = (CHAR_HEIGHT+(2*Y_SPACE))*(video->pitch) + X_SPACE*(video->BitsPerPixel/8);
    char * source = (char *) (video->PhysBasePtr + whereOnScreen);
    unsigned whereOnScreen2 = (Y_SPACE)*(video->pitch) + X_SPACE*(video->BitsPerPixel/8);
    char * dest = (char *) (video->PhysBasePtr + whereOnScreen2);
    int size = ((video->YResolution)-CHAR_HEIGHT-Y_SPACE)*(video->XResolution);
    memCpy(dest, source, size);
    for (int y = video->YResolution - (2*(CHAR_HEIGHT+Y_SPACE)) ; y < video->YResolution -(CHAR_HEIGHT+(2*Y_SPACE)); y ++) {
        for (int x = X_SPACE; x < video->XResolution-X_SPACE; x++) {
            putPixel(x, y , black);
        }
    }

}

// impreime la hora en formato hh:mm:ss el paramtero es un string que respeta el formato especificado
void printDigitalClockExp(Colour colour, unsigned char * fontExp) {
    char font;
    int xpos = XPOSITION;
    for (int y = 0; y < 36; y++) {
        for (int j = 0; j < 8; j++) {
            font = fontExp[(y*8)+j];
            for (int x = 0; x < 8; x++) {
                if (((font >> 8-x) %2) != 0){
                    putPixel(x + XPOSITION, y + YPOSITION, colour);
                } else {
                    Colour colourBlank = {0, 0, 0};
                    putPixel(x + XPOSITION, y + YPOSITION, colourBlank);
                }
            }
            XPOSITION += 8;
        }
        XPOSITION = xpos;
    }
    XPOSITION += (64 + 10); // 10 es la distancia entre digitos
}

void putDigitalColon(Colour colour) {
    printDigitalClockExp(colour, digitalColon());
}

void putDigitalNumber(Colour colour, int number) {
    printDigitalClockExp(colour, digitalClock_map(number));
}

void putTime(char * time, Colour colour) { // arreglar el caso 01:04:035
    char c;
    int i = 0;
    while ((c=time[i++])) {
        if (c == ':') {
            putDigitalColon(colour);
        } else {
            putDigitalNumber(colour, (c - '0'));
        }
    }
    XPOSITION = (video->XResolution/2) - 281;
    YPOSITION = (video->YResolution/2) - 18;
}

// la insercion de texto se realiza en el la parte inferior de la pantalla, unicamente se puede insertar en una linea del ancho de la pantalla
/*void modeComand() {
    XPOSITION2 = XPOSITION;
    YPOSITION2 = YPOSITION;
    XPOSITION = X_SPACE;
    YPOSITION = (video->YResolution) - Y_SPACE - CHAR_HEIGHT;
    putStr(">> ", white);
}

//al inicio esta en modo screen, inserta en la pantalla en la parte superior
void modeScreen() {
    XPOSITION = XPOSITION2;
    YPOSITION = YPOSITION2;
}
 */
// modo shell
//al inicio esta en modo screen, inserta en la pantalla en la parte superior
void modeScreen() {
    clearScreen();
    //modeScreen();
    //modeComand();
    XPOSITION = X_SPACE;
    YPOSITION = Y_SPACE;
}

// modo que permite mostrar el reloj en pantalla
void modeDigitalClock() {
    //XPOSITION2 = X_SPACE;
    //YPOSITION2 = Y_SPACE;
    clearScreen();
    XPOSITION = (video->XResolution/2) - 281;
    YPOSITION = (video->YResolution/2) - 18;
}
/*
// modo shell
void shellMode() {
    clearScreen();
    SHELL = TRUE;
    XPOSITION = X_SPACE;
    YPOSITION = Y_SPACE;
    putStr("$>> ", white);
}

void newComand() {
    newLine();
    putStr("$>> ", white);
}
*/
// borra la pantalla a partir de la poscion (x, y) dada
void clear(int i, int j) {
    for (int y = j; y < video->YResolution; y++) {
        for (int x = i; x < video->XResolution; x++) {
            putPixel(x, y, black);
        }
    }
}

// borra la linea de comandos en pantalla
void clearComand() {
    clear(0, (video->XResolution-CHAR_HEIGHT-Y_SPACE));
}

// borra la pantalla entera
void clearScreen() {
    clear(0, 0);
}

// longitud de palabra
int strlen(const char * str) {
    int i = 0;
    while(*(str+i)) {
        i++;
    }
    return i;
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
