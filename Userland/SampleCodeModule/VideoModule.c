#include "VideoModule.h"
#define XRESOLUTION 1024
#define YRESOLUTION 768
#define STDOUT 1
#define WRITE 1
typedef struct {
    uint8_t Red;
    uint8_t Green;
    uint8_t Blue;
} Colour;

extern unsigned int systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

void drawPixel(int x, int y, int colour) {
    systemCall(WRITE, STDOUT, 5, x, y, colour);
}

void drawDigitalColon(int colour, int x, int y) {
    drawDigitalClockExp(colour, colon_map(), x, y);
}

void drawDigitalNumber(int colour, int number, int x, int y) {
    drawDigitalClockExp(colour, clock_map(number), x, y);
}
void drawDigitalClockExp(int colour, unsigned char * fontExp, int xPosition, int yPosition) {
    char font;
    int xpos = xPosition;
    for (int y = 0; y < 36; y++) {
        for (int j = 0; j < 8; j++) {
            font = fontExp[(y*8)+j];
            for (int x = 0; x < 8; x++) {
                if (((font >> (8-x)) %2) != 0){
                    drawPixel(x + xPosition, y + yPosition, colour);
                } else {
                    drawPixel(x + xPosition, y + yPosition, 0);
                }
            }
            xPosition += 8;
        }
        xPosition = xpos;
    }
}

void drawTime(char * time, int colour) {
    int xPosition = (XRESOLUTION/2) - 281;
    int yPosition = (YRESOLUTION/2) - 18;
    char c;
    int i = 0;
    while ((c=time[i++])) {
        if (c == ':') {
            drawDigitalColon(colour, xPosition, yPosition);
        } else {
            drawDigitalNumber(colour, (c - '0'), xPosition, yPosition);
        }
        xPosition += (64 + 10); // 10 es la distancia entre digitos
    }
}
