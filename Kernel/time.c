#include <time.h>
#include "GetTime.h"
#include "String.h"
static unsigned long ticks = 0;

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
char * timeToString(int i) {
    char rsp[2];
    char first = (i/10) + '0';
    char second = (i%10) + '0';
    rsp[0] = first;
    rsp[1] = second;
    return rsp;
}

char * getTime() {
    char hours[2] = timeToString(getHours());
    char min[2] = timeToString(getMin());
    char sec[2] = timeToString(getSec());
    char time[9];
    strcpy(time, hours);
    time[2] = ":"
    strcpy(time+3, min);
    time[5] = ":"
    strcpy(time+8, second);
    return time;
}
*/