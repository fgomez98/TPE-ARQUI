#include "commands.h"
#include "stdio.h"
#include <stdint.h>


#define CLOCK 2
#define WRITE 1




extern unsigned int systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);
extern void opcodeExc();
extern void div0exc();


void help(){
  printf("HELP\n");
}

void cleanScreen(){

}

void showTime(){

}


void showDigitalHour(){
  systemCall(WRITE, CLOCK,0,0,0);
}

void show0exc(){
  div0exc();
}


void showOpcodeExc(){
  opcodeExc();
}
