#include "VideoDriver.h"
#include "Keyboard.h"

#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0

void syscall_handler(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

void syscall_handler(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6){

	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
	colour.Blue = 255;

	//putStr("entro", colour);
	switch(arg1) {
    case READ: ; break;
		case WRITE:
      write(arg2, arg3, arg4);
	 	break;

	}
}


void write(uint64_t fileDes, uint64_t toPrint, uint64_t aux1){
  Colour colour;
  colour.Red = 255;
  colour.Green = 255;
  colour.Blue = 255;

  switch(fileDes){
    case CLEAR:
      clearScreen();
    break;

    case STDOUT:
      putStr(toPrint, colour);
    break;
  }
}

void read(uint64_t fileDes, uint64_t buffer, uint64_t size, uint64_t aux1 ){
	char c =  getKeyInput();
	buffer = &c;
}