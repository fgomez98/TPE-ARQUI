#include "KeyboardDriver.h"
#include "VideoDriver.h"


static const char map[] = { '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\'', '\0', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '\0', '+', '\n',
    '\0', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\0', '{', '|', '\0',
    '}', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '-', '\0', '\0', '\0', ' '
};

void Keyboard_Handler() {
  Colour colour;
  colour.Red = 255;
  colour.Green = 255;
  colour.Blue = 255;
  int k = getKey();

   if (k > 0 && k < 128) {
        char j = map[k-1];
        if (j != '\0') {
            //newLine();
            putChar(j, colour);
        }
    }

}
