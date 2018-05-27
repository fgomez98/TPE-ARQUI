#include "VideoDriver.h"
#include <stdint.h>
//#include <string.h>
#include <lib.h>
#include <moduleLoader.h>
#include "idtLoader.h"
#include "time.h"
//#include "String.h"
#include "Keyboard.h"
#include "KeyboardDriver.h"
#include "ScanCodes.h"
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
void delay(int i) {
    for (int j = 0; j < i; j++) {
        for (int k = 0; k < i; k++) {
        }
    }
}

int main() {


	// Pone en la tabla IDT el numero de excepcion o interrupcion junto
	//con la direccion de la funcion que la atiende
	load_idt();
//	__asm__ ("int $0x00");
//	probandoExcepcion();
	Colour colour;
	colour.Red = 255;
	colour.Green = 255;
  	colour.Blue = 255;

  putStr("234", colour);

//entrando a userland
((EntryPoint)sampleCodeModuleAddress)();

putStr("no entro al userland", colour);



  /*  putStr("234", colour);
    newLine();
<<<<<<< HEAD
    putStr("234", colour);
    delay(10000);
=======
    modeDigitalClock();
    showTime(); // esta en while(1)
    putStr("234", colour);
>>>>>>> master
    //modeDigitalClock();
    //showTime(); // esta en while(1)
    putChar('s', colour);
    /* while (1) {
        if (keyPressed()) {
            putChar(getAsciiCode(getKey()), colour);
        }
    }*/
    while (1) {
        char input  = getKeyInput();
        if (input != 0) {
            putChar(input, colour);
        }
    }
*/





	return 0;
}
