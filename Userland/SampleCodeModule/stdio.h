#ifndef stdio_h
#define stdio_h

#define MAXLENGTH 100
void printf(char* fmt, ...);
void putChar(char c);
char getChar();
char *convert(unsigned int num, int base);

void scanAndPrint(char* buffer);

char getChar();


#endif
