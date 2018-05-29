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

void writeM(uint64_t fileDes, uint64_t toPrint, uint64_t size,  uint64_t aux);
void readM(uint64_t fileDes, uint64_t buffer, uint64_t size, uint64_t aux );

void syscall_handler(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);

void syscall_handler(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5){

	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
	colour.Blue = 255;


	switch(arg1) {
    case READ:

			readM(arg2, arg3, arg4, arg5);
			 break;
		case WRITE:
      writeM(arg2, arg3, arg4, arg5);
	 	break;

	}
	return 0;
}


void writeM(uint64_t fileDes, uint64_t toPrint, uint64_t size, uint64_t aux){
  Colour colour;
  colour.Red = 255;
  colour.Green = 255;
  colour.Blue = 255;

  switch(fileDes){
    case CLEAR:
      clearScreen();
    	break;

    case STDOUT:
		
			if(aux==1){ // borro un caracter
				deleteChar();
			}
			else if(aux ==2){
				newLine();
			}
			else{

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



void readM(uint64_t fileDes, uint64_t buffer, uint64_t size, uint64_t aux ){
	Colour colour;
  colour.Red = 255;
  colour.Green = 255;
  colour.Blue = 255;

	char * walter =(char *) buffer;
	*(walter) =  getKeyInput();
}
