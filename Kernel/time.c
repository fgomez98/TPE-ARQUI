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
    uintToBase((getHour()-3), buf, 10); // las horas me esta tirando cualquiera, el problema esta en que cuando son las 24 == 00
    // la cuenta es 0-3 = -3 al pasarlo a string se produce un error 
    buf[2] = ':';
    uintToBase(getMin(), buf+3, 10);
    buf[5] = ':';
    uintToBase(getSec(), buf + 6, 10);
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





