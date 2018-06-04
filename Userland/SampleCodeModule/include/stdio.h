#ifndef stdio_h
#define stdio_h

#define MAXLENGTH 100
#include <stdint.h>
#include <stdarg.h>
#include "String.h"

void printf(char* fmt, ...);
void scanAndPrint(char* buffer);
void putChar(char c);
char getChar();
int strcmp(char string1[], char string2[] );

#endif
