#include "KeyboardDriver.h"
#include "naiveConsole.h"

static const char map[] = { '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', '\0', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '\0', '+', '\n',
    '\0', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\0', '{', '|', '\0',
    '}', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-', '\0', '\0', '\0', ' '
};

void Keyboard_Handler() {
    int i = getKey();
  /*  if (i > 0 && i < 128) {
        char j = map[i-1];
        if (j != '\0') {
            ncNewline();
            ncPrintChar(j);
        }
    }
*/
}
