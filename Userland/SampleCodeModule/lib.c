#include "lib.h"
#include <stdint.h>
#include <stdarg.h>

#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0

extern void systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

void printf(char* fmt, ...){
	//probando hasta que hagan printf
  char m[]= "$>";
  systemCall(WRITE, STDOUT,  m, 0,0, 0);
	//	write(STDOUT, 0, 0,0, 0);
}


/*
void printf(char* format, ...){
	char*traverse;
	unsigned int i;
	char*s;

	va_list arg;
	va_start(arg, format);

	for(traverse = format; *traverse != '\0'; traverse++) {
		while(*traverse != '\0'){
      systemCall(WRITE, STDOUT, traverse, 0, 0 , 0);
        //putChar(*traverse);
				traverse++;
			}
			traverse++;
			switch(*traverse){
						case 'c' : i = va_arg(arg,int);     //Fetch char argument
                        systemCall(WRITE, STDOUT, i, 0, 0 , 0);
                      //  putchar(i);
                        break;

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0)
                        {
                            i = -i;

                            systemCall(WRITE, STDOUT, '-', 0, 0 , 0);
                            //putchar('-');
                        }
                        systemCall(WRITE, STDOUT, convert(i,10), 0, 0 , 0);
                        //puts(convert(i,10));
                        break;

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        systemCall(WRITE, STDOUT, convert(i,8), 0, 0 , 0);
                        //puts(convert(i,8));
                        break;

            case 's': s = va_arg(arg,char *);       //Fetch string
                          systemCall(WRITE, STDOUT, s, 0, 0 , 0);
                      //  puts(s);
                        break;

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        systemCall(WRITE, STDOUT, convert(i,16), 0, 0 , 0);
                        //puts(convert(i,16));
                        break;
				}
		}
	va_end(arg);
}

char *convert(unsigned int num, int base) {
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;

    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = Representation[num%base];
        num /= base;
    }while(num != 0);

    return(ptr);
}




*/

































/*probando
*/



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
