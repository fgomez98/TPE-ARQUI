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
#include "BuddyAllocationSystem.h"

extern uint64_t rip;
extern uint64_t stack;
extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;
extern uint64_t dir;
extern uint64_t stack;
extern uint64_t getStack();

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

	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);

	clearBSS(&bss, &endOfKernel - &bss);

	return getStackBase();
}
static char buff[8];
int main() {
    //Colour colour = {255, 255, 255};

    // Pone en la tabla IDT el numero de excepcion o interrupcion junto
    //con la direccion de la funcion que la atiende
    load_idt();
    stack = getStack();
    
////BASE ADRESS
//    putStr("base: ", colour);
//    uintToBase(&endOfKernel, buff, 10);
//    putStr(buff, colour);
//    putStr("\n", colour);
//    
////MALLOC 1
//    char * memory = mallocMemory(5000);
//    putStr("malloc1: ", colour);
//    uintToBase(memory, buff, 10);
//    putStr(buff, colour);
//    putStr("\n", colour);
//    
//    dumpMemory();
//    
////MALLOC 2
//    char * memory2 = mallocMemory(20);
//    putStr("malloc2: ", colour);
//    uintToBase(memory2, buff, 10);
//    putStr(buff, colour);
//    putStr("\n", colour);
//    
//    dumpMemory();
//    
//    int i = 0;
//    memory2[0] = 'h';
//    memory2[1] = 'o';
//    memory2[2] = 'l';
//    memory2[3] = 'a';
//    memory2[4] = '\n';
//    memory2[5] = '\0';
//    while (*(memory2+i) != '\0') {
//        putChar(*(memory2+i), colour);
//        i++;
//    }
//    
////FREE 1
//    freeMemory(memory);
//    dumpMemory();
//    
////REALLOC 6
//    char * memory6 = reallocMemory(memory2, 5000);
//    putStr("realloc6: ", colour);
//    uintToBase(memory6, buff, 10);
//    putStr(buff, colour);
//    putStr("\n", colour);
//    
//    dumpMemory();
//    
//    i = 0;
//    while (*(memory6+i) != '\0') {
//        putChar(*(memory6+i), colour);
//        i++;
//    }
//    
////FREE 2
//    freeMemory(memory2);
//    dumpMemory();
//    for (int i = 0; i < 5 ; i++) {
//        putChar(*(memory2+i), colour);
//    }
//    
//////MALLOC 3
//    char * memory3 = mallocMemory(2000);
//    putStr("malloc3: ", colour);
//    uintToBase(memory3, buff, 10);
//    putStr(buff, colour);
//    putStr("\n", colour);
//    
//    
//////MALLOC 4
//    char * memory4 = mallocMemory(2000);
//    putStr("malloc4: ", colour);
//    uintToBase(memory4, buff, 10);
//    putStr(buff, colour);
//    putStr("\n", colour);
//    
////MALLOC 5
//    char * memory5 = mallocMemory(5000);
//    putStr("malloc5: ", colour);
//    uintToBase(memory5, buff, 10);
//    putStr(buff, colour);
//    putStr("\n", colour);
//    
//    dumpMemory();
    
    rip = (uint64_t)sampleCodeModuleAddress;
    ((EntryPoint)sampleCodeModuleAddress)();

	return 0;
}
