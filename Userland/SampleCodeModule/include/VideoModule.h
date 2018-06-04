#ifndef VideoModule_h
#define VideoModule_h

#include <stdint.h>
#include "ClockFont.h"

typedef struct {
    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
} Colour;

void drawTime(char * time, Colour colour);
void drawPixel(int x, int y, Colour colour);

#endif