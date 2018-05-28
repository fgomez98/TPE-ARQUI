#include "commands.h"
#include <stdint.h>


#define CLOCK 2
#define WRITE 1


extern void systemCall (uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

void help(){

}

void showHour(){

}

void showDigitalHour(){
  systemCall(WRITE, CLOCK,0,0,0,0);
}

void show0exc(){

}


void showOpcodeExc(){

}
