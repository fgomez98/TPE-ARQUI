#include "commands.h"
#include "stdio.h"
#include <stdint.h>


#define CLOCK 2
#define WRITE 1
#define STDOUT 1
#define READ 0
#define STDIN 0
#define CLEAR 0



extern unsigned int systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);
extern void opcodeExc();



void help(){
  printf("HELP\n");
}

void cleanScreen(){
  systemCall(WRITE, CLEAR, 0,0, 0);
}

void showTime(){

}

/*
void showTime() {
    Colour myColours[5] = {colour1, colour2, colour3, colour4, colour5};
    modeDigitalClock();
    char * time;
    char key;
    while (1) {
        key = getKeyInput();
        switch (key) {
            case 'c': //hotkey
                colourIndex = (colourIndex+1)%COLOUR_SIZE;
                void beep();
                break;
            case 'q': // beep
                modeScreen();
                return;
                break;
        }
        time = getTime();
        putTime(time, myColours[colourIndex]);
    }
}
*/
void showDigitalHour(){
  systemCall(CLOCK, 1,0,0,0);

  char key;
  while (1) {
    systemCall(READ, STDIN, &key,1, 1);
      switch (key) {
          case 'c': //hotkey
              systemCall(CLOCK, 2,0,0,0);
              break;
          case 'q': // beep
              systemCall(CLOCK, 1, 0,0,0);
              return;
              break;
      }
      systemCall(CLOCK, 3,0,0,0);

  //systemCall(WRITE, CLOCK,0,0,0);
}

}

int div100(int n) {
  return 100 / n;
}


void divi(){
  div100(0);
}


void showOpcodeExc(){
  opcodeExc();
}
