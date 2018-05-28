#include "VideoDriver.h"
#include "Keyboard.h"
#include <stdint.h>

#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0
#define CLOCK 2
void probando(uint64_t* toPrint, uint64_t size,  Colour colour);

void syscall_handler(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

void syscall_handler(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6){

	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
	colour.Blue = 255;
	char a = 'a';

	switch(arg1) {
    case READ: ; break;
		case WRITE:
      write(arg2, arg3, arg4);
	 	break;

	}
}


void write(uint64_t fileDes, uint64_t toPrint, uint64_t size){
  Colour colour;
  colour.Red = 255;
  colour.Green = 255;
  colour.Blue = 255;

  switch(fileDes){
    case CLEAR:
      clearScreen();
    	break;

    case STDOUT:
			switch(size){
				case 1:
				putChar(toPrint, colour);
				break;

				default:
				putStr(toPrint, colour);
				 break;
			}

    	break;
			case CLOCK:
				showTime();
			break;
  }
}

/*
void probando(uint64_t* toPrint, uint64_t size,  Colour colour){
	int i=0;
	putStr("entro", colour);
	while(i< size){
		putChar(toPrint[i], colour);
	}
}
*/



void read(uint64_t fileDes, uint64_t buffer, uint64_t size, uint64_t aux1 ){
	char c =  getKeyInput();
	buffer = &c;
}
