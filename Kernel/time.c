#include <time.h>
#include "TimeDriver.h"
#include "String.h"
#include "lib.h"
#include "VideoDriver.h"
static unsigned long ticks = 0;
static Colour white = {255, 255, 255};

void timer_handler() {
	ticks++;
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 18;
}

char * getTime() {
    static char buf[8] = {0};
    uintToBase(abs((getHour()-3)%24), buf, 10); 
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

void showTime() {
    modeDigitalClock();
    char * time;
    while (1) {
        time = getTime();
        putTime(time, white);
    }
}






