#include "VideoDriver.h"
#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <moduleLoader.h>
#include "idtLoader.h"
#include "time.h"
#include "String.h"

extern void probandoExcepcion();

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;

static void * const sampleCodeModuleAddress = (void*)0x400000;
static void * const sampleDataModuleAddress = (void*)0x500000;



typedef int (*EntryPoint)();

void clearBSS(void * bssAddress, uint64_t bssSize) {
	memset(bssAddress, 0, bssSize);
}

void * getStackBase()
{
	return (void*)(
		(uint64_t)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(uint64_t)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary()
{
	//char buffer[10];

	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);

	clearBSS(&bss, &endOfKernel - &bss);

	return getStackBase();
}

/*{
	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
  colour.Blue = 255;
	switch(arg1) {
		case 0: putStr("PRobando handler", colour ); break;

	}
}*/
int countDigits(int num){
    int dig = 1;
    while((num/=10) != 0) dig++;
    return dig;
}

char * intToStr(int num){
    int dig = countDigits(num);
    char numbers[4] = {0};
    int count=0;
    while(count!=dig){
        numbers[dig-1-count++]=num%10+48;
        num /= 10;
    }
    numbers[dig]=0;
    return numbers;
}

int main() {
	// Pone en la tabla IDT el numero de excepcion o interrupcion junto
	//con la direccion de la funcion que la atiende
	load_idt();
	probandoExcepcion();
	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
  	colour.Blue = 255;
    putStr("hola", colour);
		newLine();
    putStr("234", colour);
    newLine();
    modeDigitalClock();
    showTime(); // esta en while(1) 

	return 0;
}



void syscall_handler(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4){
	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
		colour.Blue = 255;
	switch(arg1) {
		case 0: putStr("probando syscall handler", colour);; break;
		case 1: ; break;
	}
}
