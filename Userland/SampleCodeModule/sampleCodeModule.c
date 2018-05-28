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

extern void systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);


#include "commands.h"
//#include "lib.h"
void printf(char* fmt, ...);

int main() {

	//char command[MAXLENGTH];//AVERIGUAR EL TOPE
	//int running = 1;
//	while (running){


	 printf("$>");
	 showDigitalHour();

		/*	scanf("%s",command); //pone en command lo que el usuario ingreso hasta apretar enter

			if(strcmp("ayuda", command) == 0){
					help();
			}
			else if(strcmp("hora", command) == 0){
				showHour();
			}
			else if(strcmp("horaDigital", command) == 0){
				showDigitalHour();
			}
			else if(strcmp("divisionPor0exc", command) == 0){
				show0exc();
			}
			else if(strcmp("", command) == 0){
				showOpcodeExc();
			}
			else if(strcmp("salir", command) == 0){
				running = 0;
			}
			else{
				printf("Comando no encontrado");
			}

*/

//	}

	return 2;
}
