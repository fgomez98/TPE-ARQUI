#include "shell.h"
#include "commands.h"
#include "stdio.h"
#include "stdlib.h"

void initializeShell(){

  printf("Welcome to the shell!! Please type help to get a list of our commands\n");

  static char command[MAXLENGTH];
  int running = 1;
  while (running){

    printf("$>");
    scanAndPrint(command);

    if(strcmp("help", command) == 0){
        help();
    }
    else if(strcmp("digitalTime", command) == 0){
      showDigitalHour();
    }
    else if(strcmp("time", command) == 0){
      showTime();
    }
    else if(strcmp("clear", command) == 0){
      cleanScreen();
    }
    else if(strcmp("zero division", command) == 0){
      divi();
    }
    else if(strcmp("invalid opcode", command) == 0){
      showOpcodeExc();
    }
    else if(strcmp("exit", command) == 0){
      running = 0;
    }
    else{
      printf("\nUnknown command, type help\n");
    }

  }
   printf("\n\n\nSee you soon!");
}
