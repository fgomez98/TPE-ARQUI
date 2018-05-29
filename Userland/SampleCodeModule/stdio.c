#include <stdint.h>
#include <stdarg.h>
#include"stdio.h"

#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0

static char buffer[MAXLENGTH];

extern unsigned int systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

char getChar(){
	char c = 0;
	while(c==0){
    systemCall(READ, STDIN,(uint64_t) &c, 1, 0, 0);
  //	read(STDIN, &c, 1, 0, 0);
	}

	return c;
}

void putChar(char c){
	systemCall(WRITE,STDOUT,(uint64_t) &c,1,0,0);
}

void putString(char* string){
int length;
  for(length = 0; string[length] != '\0'; length ++);
  systemCall(WRITE,STDOUT,string,length,0,0);
}

void printf(char* fmt, ...){
<<<<<<< Updated upstream
	//probando hasta que hagan printf
//  char m[] ="hola";
  //char f[] ="chau";

//  systemCall(WRITE, STDOUT,  m, 2,0, 0);
  systemCall(WRITE, STDOUT,  fmt, 2,0, 0);
 return;
	//	write(STDOUT, 0, 0,0, 0);
=======
  va_list args;
  va_start(args, fmt);

  unsigned int i;
  char* iterate = fmt;
  char* s;

  while(*iterate != '\0'){
    if(*iterate != '%'){
      putChar(*iterate);
      iterate++;
    }else{
      iterate++;
      switch(*iterate){
        case 'c': i = va_arg(args, int);
                      putChar(i);
                      break;

        case 'd': i = va_arg(args, int);
                  if( i < 0){
                    i = -i;
                    putChar('-');
                  }
                  putString(convert(i,10));
                  break;
        case 's': s = va_arg(args, char*);
                  putString(s);
                  break;

        case 'x': i = va_arg(args, unsigned int);
                  putString(convert(i,16));
                  break;

        case 'o': i = va_arg(args, unsigned int);
                  putString(convert(i,8));
                  break;

      }
    }
  }
  va_end(args);
}

char *convert(unsigned int num, int base) {
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
>>>>>>> Stashed changes
}

void scanAndPrint(char* buffer){
  char k;
  k = getChar();
  systemCall(WRITE, STDOUT,  k, 1,0, 0);
}


char getChar(){
  char c=0;
	while(1) {
    systemCall(READ, STDIN, &c,1, 1, 0);
    if ( c > 0 && c <128) {
      return c;
    }
	}
  return 0;
}
