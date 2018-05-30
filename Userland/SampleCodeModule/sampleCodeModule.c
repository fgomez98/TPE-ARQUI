/* sampleCodeModule.c */
/*
char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;*/


#include <stdint.h>
#include <stdarg.h>
#include"stdio.h"

#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0


extern void systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);


#include "commands.h"
//#include "lib.h"
void printf(char* fmt, ...);

int main() {
    printf("hola %d  %s   %c", 5, "walter", 95);
	help();



	static char command[MAXLENGTH];//AVERIGUAR EL TOPE
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
			else if(strcmp("digitalTime", command) == 0){
				showTime();
			}
			else if(strcmp("clear", command)==0){
				cleanScreen();
			}
			else if(strcmp("div", command) == 0){
				divi();
			}
			else if(strcmp("opcodeExc", command) == 0){
				showOpcodeExc();
			}
			else if(strcmp("exit", command) == 0){
				running = 0;
			}
			else{
				printf("Unknown command, type help");
			}

	}
	printf("See you soon!");

	return 2;
}
