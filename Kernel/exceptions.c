#include "VideoDriver.h"

#define ZERO_EXCEPTION_ID 0
#define INVALIDOPCODE_EXCEPTION_ID 1

//hacer despues el .h
static void zero_division();
static void invalid_opcode();
void printIpAndRegs(uint64_t* stackPointer);

void exceptionDispatcher(uint64_t exception, uint64_t *stackPointer) {
	switch(exception){
		case ZERO_EXCEPTION_ID:
			zero_division();
			//como hice pushstate antes de llamar a la handler, tengo todos los registros
			//a partir de donde empieza el stackPointer
		break;
		case INVALIDOPCODE_EXCEPTION_ID:
			invalid_opcode();
		break;
	}
	printIpAndRegs(stackPointer);
}

static void zero_division() {
	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
	colour.Blue = 255;
	putStr("ERROR: DIVISION POR 0", colour);
	return;
}

static void invalid_opcode(){
	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
	colour.Blue = 255;
	putStr("ERROR: CODIGO DE OPERACION INVALIDO", colour);
}


void printIpAndRegs(uint64_t* stackPointer){
	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
	colour.Blue = 255;

	 char* regs[]= {"RAX ","RBX ","RCX ","RDX ","RBP ","RDI ","RSI ","R8 ","R9 ","R10 ","R11 ","R12 ","R13 ","R14 ","R15  "};
	 newLine();
	 /*ESTO ESTA BIEN?? stack frame tiene la direccion del
	 r15. adelante esta r14 y asi sucesivamente. uno antes de r15 esta la direccion
	 de retorno de la handler que seria el rip. esto esta bien???*/
	 putStr("RIP ", colour);
	 putHexa(*(stackPointer-4), colour);
	for (int i =14, j=0; i>=0; i--, j++){
		newLine();
		putStr(regs[i], colour);
		putHexa(stackPointer[j], colour);
	}



	newLine();
}
