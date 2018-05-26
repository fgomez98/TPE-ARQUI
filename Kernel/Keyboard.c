#include "KeyboardDriver.h"
#include "VideoDriver.h"
#include "ScanCodes.h"
#include "Keyboard.h"
#define FALSE 0
#define TRUE 1
#define SIZE 100

static int buffer[SIZE];
static int putIndex = 0;
static int getIndex = 0;
static int size = 0;
static int SHIFT_ON = FALSE;
static int CAPS_ON = FALSE;
static int CNTRL_ON = FALSE;

void Keyboard_Handler() { // una vez apretada una tecla se soltara una interrupcion y luego la idt llama a esta funcion
    unsigned int scan = getKey();
    char input;
    if (scan & 0x80) { // si el primer bir esta en 1 entnces una tecla fue soltada
        switch (scan) {
            case RSHIFT_R: // shift
                SHIFT_ON = FALSE;
                break;
            case LSHIFT_R: // shift
                SHIFT_ON = FALSE;
                break;
            case CAPS_R:  // caps
                CAPS_ON = FALSE;
                break;
            case CTRL_R: //  cntrl
                CNTRL_ON = FALSE;
                break;
        }
    } else { // se apreto una tecla, si alguna ya fue apretada antes y se mantiene pulasada esta enviara multiples interrupciones, si fuese una tecla especial esta estaria seteada en TRUE y al apretar luego una tecla accedemos a su respectivo mapa
        switch (scan) {
            case RSHIFT: // shift
                SHIFT_ON = TRUE;
                break;
            case LSHIFT: // shift
                SHIFT_ON = TRUE;
                break;
            case CAPS:  // caps
                CAPS_ON = TRUE;
                break;
            case CTRL: //  cntrl
                CNTRL_ON = TRUE;
                break;
        }
        if (SHIFT_ON) {
            input = getAsciiShiftCode(scan);
            addChar(input);
        } else if (CAPS_ON) {
            input = getAsciiCode(scan);
            if (input>='a' && input<='z') {
                input -= 32;
            }
            addChar(input);
        } else {
            input = getAsciiCode(scan);
            addChar(input);
        }
    }
}

int isEmpty() {
    if (size > 0) {
        return 0;
    } else {
        return 1;
    }
}

char getchar() {
    if (size == 0) {
        return '\n'; // aunque ya estaria guardado un /n no?
    }
    char c = buffer[getIndex--];
    getIndex = getIndex%SIZE;
    size--;
    return c;
}

void addChar(char input) {
    buffer[putIndex++] = input;
    putIndex = putIndex%SIZE;
    size++;
}
