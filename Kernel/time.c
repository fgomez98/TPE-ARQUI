#include <time.h>
#include "TimeDriver.h"
#include "String.h"
#include "lib.h"
#include "VideoDriver.h"
#include "Keyboard.h"
#include "Beep.h"
#define COLOUR_SIZE 6
static unsigned long ticks = 0;
/*
static Colour colour1 = {255, 255, 255};
static Colour colour2 = {180, 40, 18};
static Colour colour3 = {200, 156, 12};
static Colour colour4 = {233, 80, 167};
static Colour colour5 = {46, 230, 210};
static Colour colour6 = {200, 130, 40};
static int colourIndex = 0;
 */
void timer_handler() {
	ticks++;
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 18;
}
/*
char * getTime() {
    static char buf[8] = {0};
    int hour = getHour()-3;
    if (hour < 0) {
        hour += 24;
    }
    uintToBase(hour, buf, 10);
    if (buf[1] == 0) {
        buf[1] = buf[0];
        buf[0] = '0';
    }
    buf[2] = ':';
    uintToBase(getMin(), buf+3, 10);
    if (buf[4] == 0) {
        buf[4] = buf[3];
        buf[3] = '0';
    }
    buf[5] = ':';
    uintToBase(getSec(), buf + 6, 10);
    if (buf[7] == 0) {
        buf[7] = buf[6];
        buf[6] = '0';
    }
    return buf;
}
*/
/*
void showTime() {
    Colour myColours[5] = {colour1, colour2, colour3, colour4, colour5};
    modeDigitalClock();
    char * time;
    char key;
    while (1) {
        key = getKeyInput();
        switch (key) {
            case 'c': //hotkey
                colourIndex = (colourIndex+1)%COLOUR_SIZE;
                void beep();
                break;
            case 'q': // beep
                modeScreen();
                return;
                break;
        }
        time = getTime();
        putTime(time, myColours[colourIndex]);
    }
}
*/
/*
void updateCoulourAndBeep(){
	colourIndex = (colourIndex+1)%COLOUR_SIZE;
	void beep();
}


void displayTime(){
	char * time;
	Colour myColours[5] = {colour1, colour2, colour3, colour4, colour5};

	time = getTime();
	putTime(time, myColours[colourIndex]);
}
 */
