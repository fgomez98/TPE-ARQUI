#include "VideoDriver.h"
#include "Keyboard.h"
#include <stdint.h>
#include "math.h"
#include "Beep.h"
#include "TimeDriver.h"
#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0
#define CLOCK 2
#define BEEP 3


void write(uint64_t arg2, uint64_t arg3, uint64_t arg4,  uint64_t arg5,  uint64_t arg6);
void read(uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5 , uint64_t arg6);

void syscall_handler(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

void syscall_handler(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6) {

	switch(arg1) {

    case READ:
			read(arg2, arg3, arg4, arg5, arg6);
			 break;
		case WRITE:
      write(arg2, arg3, arg4, arg5, arg6);
	 	break;
	}
}

void write(uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6){
  Colour colour;
  colour.Red = 255;
  colour.Green = 255;
  colour.Blue = 255;
  switch(arg2){
    case CLEAR:
			modeScreen();
    	break;
    case STDOUT:
        switch(arg3){
            case 0:
                putStr(arg4, colour);
                break;
            case 1:
                putChar(arg4, colour);
                break;
            /*
            case CLOCK:
                switch (arg4){
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
             */
            case 3:
                deleteChar();
                break;
            case 4:
                newLine();
                break;
            case 5:
                ; // Nada
                Colour colour2 = intToRGB(arg6);
                putPixel(arg4, arg5, colour2);
                break;
            case 6:
                ; //Nada
                int * p = (int *) arg5;
                switch(arg4){
                    case 0:
                        *(p) = getHour();
                        break;
                    case 1:
                        *(p) = getMin();
                        break;
                    case 2:
                        *(p) = getSec();
                        break;
                }
                break;
        }
        break;
    case BEEP:
          beep();
          break;
  }
}

void read(uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5 , uint64_t arg6){
	char * p =(char *) arg3;
	*(p) =  getKeyInput();
}
