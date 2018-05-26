#include "lib.h"

//se queda en un while hasta que el usuario aprieta enter o escribio
//mas de lo que el buffer soporta
//HAY QUE HACER LO DEL FMT?? COMO SE HACE
void scanf(char* fmt, char* buffer){
	char k;
	int i =0;
	while(((k = getChar()) != '\n')  && i< MAXLENGTH - 1){
		buffer[i++] = k;
	}
	buffer[i] = 0;
}


//FALTA HACER. DESPUES METER PRINTF Y EL RESTO EN OTRA CARPETA ASI QUEDA MAS ORDENADO
void printf(char* fmt, ...){

}


//FALTA HACER
char getChar(){
	char ret = 'c'; //probando

	return ret;
}








int strcmp(char string1[], char string2[] )
{
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
