#include "stdio.h"
#include "lib.h"
#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0


extern unsigned int systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);

void scanAndPrint(char* buffer) {

  char k;
  int i=0;

  while(((k = getChar()) != '\n')  && i< MAXLENGTH - 1){
    if(k == '\b'){
      systemCall(WRITE, STDOUT,0,0,1);
      i--;
    }
    else if (k > 0 && k < 127) {
      systemCall(WRITE, STDOUT, k,1,0);
      buffer[i++] = k;
    }

  	}
    buffer[i]=0;

  /*k = getChar();
  if (k > 0 && k < 127) {
    systemCall(WRITE, STDOUT, k,1,0);
    buffer[i++] = k;
  }
  else if(k == '\b'){
    systemCall(WRITE, STDOUT,0,0,1);
    i--;
  }
  buffer[i]=0;
*/
}

void putChar(char c) {
    systemCall(WRITE, STDOUT, c,1,0);
}

void putString(char * str) {
    systemCall(WRITE, STDOUT, str,0,0);
}
char getChar(){
  char c=0;
	while(1) {
    systemCall(READ, STDIN, &c,1, 1);
    if ( c > 0 && c <128) {
      return c;
    }
	}
  return 0;
}

void printf(char* fmt, ...) {
    
    va_list args;
    va_start(args, fmt);
    
    int i;
    char* s;
    char printable[64];
    
    while(*fmt){
        if(*fmt != '%'){
            putChar(*fmt);
        }else{
            fmt++;
            switch(*fmt){
                case 'c':
                    i = (char) va_arg(args, int);
                    putChar((char)i);
                    break;
                case 'd':
                    i = va_arg(args, int);
                    uintToBase(i, printable, 10);
                    putString(printable);
                    break;
                case 's':
                    s = (char*) va_arg(args, char*);
                    putString(s);
                    break;
            }
        }
        fmt++;
    }
    va_end(args);
}

char *convert(int num, int base) {
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;
    
    ptr = &buffer[49];
    *ptr = '\0';
    
    do
    {
        *--ptr = Representation[num%base];
        num /= base;
    }while(num != 0);
    
    return(ptr);
    
}
