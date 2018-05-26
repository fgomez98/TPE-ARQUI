#include <time.h>
#include <stdint.h>
#include "Keyboard.h"

static void int_20();

void irqDispatcher(uint64_t irq) {
	switch (irq) {
		case 0:
			int_20();
			break;
        case 1:
            Keyboard_Handler();
            break;
	}
	return;
}

void int_20() {
	timer_handler();
}


