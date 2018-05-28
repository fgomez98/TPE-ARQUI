#include "lib.h"
#include <stdint.h>

#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0

extern void systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);


/*

ESTAS FUNCIONES ARMABAN QUILOMBO. PREGUNTAR POR QUE
void write(uint64_t fileDesc, uint64_t toPrint, uint64_t size, uint64_t aux1, uint64_t aux2);

void read(uint64_t fileDesc, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2);


void write(uint64_t fileDesc, uint64_t toPrint, uint64_t size, uint64_t aux1, uint64_t aux2){
	//systemCall(WRITE, fileDesc, toPrint,size,aux1 ,aux2 );
}

void read(uint64_t fileDesc, uint64_t buffer, uint64_t size, uint64_t aux1, uint64_t aux2){
	systemCall(READ, fileDesc , buffer, size,aux1 ,aux2);
}



void scanf(char* fmt, char* buffer){
	char k;
	int i =0;
	while(((k = getChar()) != '\n')  && i< MAXLENGTH - 1){
		buffer[i++] = k;
	}
	buffer[i] = 0;
}


char getChar(){
	char c = 0;
	while(c==0){
    systemCall(READ, STDIN, &c, 1, 0, 0);
  //	read(STDIN, &c, 1, 0, 0);
	}

	return c;
}



//FALTA HACER. DESPUES METER PRINTF Y EL RESTO EN OTRA CARPETA ASI QUEDA MAS ORDENADO
void printf(char* fmt, ...){
	//probando hasta que hagan printf
	const char* probando = "probando";
  systemCall(WRITE, STDOUT,  probando, 0,0, 0);
	//	write(STDOUT, 0, 0,0, 0);
}




int strcmp(char string1[], char string2[] ){
    for (int i = 0; ; i++)
    {
        if (string1[i] != string2[i])
        {
            return string1[i] < string2[i] ? -1 : 1;
        }

        if (string1[i] == '\0')
        {
            return 0;
        }
    }
}
*/
