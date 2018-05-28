#include <stdint.h>
#include <stdarg.h>
#include"stdio.h"

#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0


extern void systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

void printf(char* fmt, ...){
	//probando hasta que hagan printf
//  char m[] ="hola";
  //char f[] ="chau";
  
//  systemCall(WRITE, STDOUT,  m, 2,0, 0);
  systemCall(WRITE, STDOUT,  fmt, 2,0, 0);
 return;
	//	write(STDOUT, 0, 0,0, 0);
}
