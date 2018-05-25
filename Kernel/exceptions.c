#include "VideoDriver.h"

#define ZERO_EXCEPTION_ID 0


static void zero_division();
void printIpAndRegs(uint64_t* stackPointer);

void exceptionDispatcher(uint64_t exception, uint64_t *stackPointer) {
	switch(exception){
		case ZERO_EXCEPTION_ID:
			zero_division();
			//como hice pushstate antes de llamar a la handler, tengo todos los registros
			//a partir de donde empieza el stackPointer
			printIpAndRegs(stackPointer);
		break;
	}

}

static void zero_division() {
	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
	colour.Blue = 255;
	putStr("ERROR: DIVISION POR 0", colour);
//imprime  instruction pointer y registros en el momento del error.

}

//ME FALTA IMPRIMIR EL IP
void printIpAndRegs(uint64_t* stackPointer){
	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
	colour.Blue = 255;

	 char* regs[]= {"RAX ","RBX ","RCX ","RDX ","RBP ","RDI ","RSI ","R8 ","R9 ","R10 ","R11 ","R12 ","R13 ","R14 ","R15  ","RIP "};
	//hay 16 registros
	//chequear esto. la macro los pushea en el orden: push rax, push rbx... etc
	//esto significa que el sp va a quedar apuntando al ultimo pusheado que es el r15
	//entonces en la direccion del sp tengo al r15 no?
	for (int i =15, j=0; i>=0; i--, j++){
		newLine();
		putStr(regs[i], colour);
		putHexa(stackPointer[j], colour);
	}

/*	for (int i =0; i<16; i++){
		newLine();
		putStr(regs[i], colour);
		putStr(stackPointer[i], colour);
	}
*/
	newLine();
}
