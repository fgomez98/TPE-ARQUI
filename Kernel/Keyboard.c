#include "KeyboardDriver.h"
#include "VideoDriver.h"
#include "scanCodes.h"
#define FALSE 0
#define TRUE 1
#define SIZE 100
static const char map[] = { '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', '\0', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '\0', '+', '\n',
    '\0', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\0', '{', '|', '\0',
    '}', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-', '\0', '\0', '\0', ' '
};

static int buffer[SIZE];
static int currentIndex = 0;
static int prevIndex = 0;
static int size = 0;
static int SHIFT_ON = FALSE;
static int CAPS_ON = FALSE;
static int CNTRL_ON = FALSE;

void Keyboard_Handler() { // una vez apretada una tecla se soltara una interrupcion y luego la idt llama a esta funcion
    unsigned int keyScanned = getKey();
    switch (keyScanned) {
        case LSHIFT:
            SHIFT_ON = TRUE;
            break;
        case RSHIFT:
            SHIFT_ON = TRUE;
            break;
        case CTRL:
            CNTRL_ON = TRUE;
            break;
        case CAPS:
            CAPS_ON = TRUE;
            break;
    }
    char c;
    if (SHIFT_ON) {
        c = scan_code_ascii_shift[keyScanned];
    } if (CAPS_ON) {
        c = scan_code_ascii[keyScanned];
        c -= 32; // lo paso a upper case
    } else {
        c = scan_code_ascii[keyScanned];
    }
    
}
