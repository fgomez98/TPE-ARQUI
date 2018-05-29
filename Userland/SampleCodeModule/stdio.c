#include <stdint.h>
#include <stdarg.h>
#include"stdio.h"

#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0


extern unsigned int systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);

void printf(char* fmt, ...){
	//probando hasta que hagan printf
//  char m[] ="hola";
  //char f[] ="chau";

//  systemCall(WRITE, STDOUT,  m, 2,0, 0);
  systemCall(WRITE, STDOUT,  fmt, 2,0);
 return;
	//	write(STDOUT, 0, 0,0, 0);
}
/*
while (1) {
        char c = getKeyInput();
        if (c == '\b') {
            deleteChar();
        } else if (c == '\n') {
            newLine();
        }else if (c > 0 && c < 127) {
            putChar(c, colour);
        }
    }*/


void scanAndPrint(char* buffer){

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

int strcmp(char string1[], char string2[] ){
    for (int i = 0; ; i++)
    {
        if (string1[i] != string2[i])
        {
            return string1[i] < string2[i] ? -1 : 1;
        }

        if (string1[i] == '\0')
        {
            return 0;
        }
    }
}
