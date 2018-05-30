#include "VideoDriver.h"
#include "Keyboard.h"
#include <stdint.h>
#include "math.h"

#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0
#define CLOCK 2
#define DIVIDE 3
void probando(uint64_t* toPrint, uint64_t size,  Colour colour);

void writeM(uint64_t fileDes, uint64_t toPrint, uint64_t size,  uint64_t aux);
void readM(uint64_t fileDes, uint64_t buffer, uint64_t size, uint64_t aux );

void syscall_handler(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);
int divide(uint64_t ans, uint64_t a, uint64_t b);

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
		case DIVIDE:

		 	divide(arg2, arg3, arg4);

		break;

		case CLOCK:
			switch (arg2){
				case 0:
				modeDigitalClock();
				break;
				case 1:
				modeScreen();
				break;
				case 2:
				updateCoulourAndBeep();
				break;
				case 3:
				displayTime();

				break;
			}

		break;

	}
	return 0;
}


//METER ESTA EN OTRO .C
int divide(uint64_t ans, uint64_t a, uint64_t b){

	int * rta =(int *) ans;
	int res = a/b;
	*(rta) = res;

	return res;
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

	  }
	}
}





void readM(uint64_t fileDes, uint64_t buffer, uint64_t size, uint64_t aux ){
	Colour colour;
  colour.Red = 255;
  colour.Green = 255;
  colour.Blue = 255;

	char * walter =(char *) buffer;
	*(walter) =  getKeyInput();
}
