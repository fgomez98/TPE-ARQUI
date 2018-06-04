#include "commands.h"
#include "stdio.h"
#include <stdint.h>
#include "VideoModule.h"
#include "TimeModule.h"
#define CLOCK 2
#define WRITE 1
#define STDOUT 1
#define READ 0
#define STDIN 0
#define CLEAR 0
#define BEEP 3
#define SIZE 5
extern unsigned int systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);
extern void opcodeExc();

static const int mycolours[SIZE] = {12354, 658456, 736534, 12444, 0xFF};

void help(){
  printf("\nHELP:\n");
  printf("\n");
  printf("help - prints a list containing all the available commands and its descriptions\n");
  printf("digitalTime - displays time in digital format. Press c to change colour and q to exit\n");
  printf("time - displays current time\n");
  printf("clear - clears screen\n");
  printf("zero division - shows how the cero division exception is handled\n");
  printf("invalid opcode - shows how the cero division exception is handled\n");
  printf("exit - exits from shell\n");
}

void cleanScreen(){
  systemCall(WRITE, CLEAR, 0,0, 0, 0);
}

void showTime() {
    printf("\n");
    printf(getTime());
    printf("\n");
}

void showDigitalHour(){ //NO ESTA CAMBIANDO DE COLOR NOSE POR QUE
    cleanScreen();
    char key;
    int j = 0;
    while (1) {
        systemCall(READ, STDIN, &key,1, 1,0);
        switch (key) {
            case 'c': //hotkey
                systemCall(WRITE, BEEP, 0,0,0,0);
                j++;
                j = j % SIZE;
                break;
            case 'q':
                cleanScreen();
                return;
                break;
        }
        drawTime(getTime(), mycolours[j]);
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
