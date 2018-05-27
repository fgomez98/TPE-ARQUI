#include <stdint.h>
#include <idtLoader.h>
#include <defs.h>
#include <interrupts.h>

//esto hace que todos los fields del struct queden contiguos
#pragma pack(push)		/* Push de la alineación actual */
#pragma pack (1) 		/* Alinear las siguiente estructuras a 1 byte */

/* Descriptor de interrupcion */
typedef struct {
  uint16_t offset_l, selector;
  uint8_t cero, access;
  uint16_t offset_m;
  uint32_t offset_h, other_cero;
} DESCR_INT;

#pragma pack(pop)		/* Reestablece la alinceación actual */



DESCR_INT * idt = (DESCR_INT *) 0;	// IDT de 255 entradas

static void setup_IDT_entry (int index, uint64_t offset);

void load_idt() {
  setup_IDT_entry (0x00, (uint64_t)&_exception0Handler);//division por 0
  setup_IDT_entry (0x06, (uint64_t)&_exceptionInvalidOpcodeHandler);//codigo de operacion invalido

  //esta vino escrita, es la del timer tick.
  setup_IDT_entry (0x20, (uint64_t)&_irq00Handler);

  setup_IDT_entry (0x21, (uint64_t)&_irq01Handler); //itnerrupción de teclado
  setup_IDT_entry (0x80, (uint64_t)&_syscall_handler);

	//Solo interrupcion timer tick habilitadas
	picMasterMask(0xFE);
	picSlaveMask(0xFF);
    //Solo interrupcion teclado habilitadas
    picMasterMask(0xFD);
    picSlaveMask(0xFF);

	_sti();
}

/*idt[0h] es la pos 0 de la tabla, idt[80h] es la pos 80h de la tabla.
Lo que hace esta función es poner en la posición index de la tabla
la dirección de la función que atiende a la interrupción
*/
static void setup_IDT_entry (int index, uint64_t offset) {
  idt[index].selector = 0x08;
  idt[index].offset_l = offset & 0xFFFF;
  idt[index].offset_m = (offset >> 16) & 0xFFFF;
  idt[index].offset_h = (offset >> 32) & 0xFFFFFFFF;
  idt[index].access = ACS_INT;
  idt[index].cero = 0;
  idt[index].other_cero = (uint64_t) 0;
}
