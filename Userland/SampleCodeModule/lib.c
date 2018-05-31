#include "lib.h"
#include <stdint.h>
#include <stdarg.h>

#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0

extern void systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

uint64_t uintToBase(uint64_t value, char * buffer, uint64_t base) {
    char *p = buffer;
    char *p1, *p2;
    uint64_t digits = 0;

    //Calculate characters for each digit
    do {
        uint64_t remainder = value % base;
        *p++ = (remainder < 10) ? remainder + '0' : remainder + 'A' - 10;
        digits++;
    }
    while (value /= base);
    // Terminate string in buffer.
    *p = 0;
    //Reverse string in buffer.
    p1 = buffer;
    p2 = p - 1;
    while (p1 < p2) {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }
    return digits;
}


/*



int strcmp(char string1[], char string2[] ){
    for (int i = 0; ; i++)
    {
        if (string1[i] != string2[i])
        {
            return string1[i] < string2[i] ? -1 : 1;
        }

        if (string1[i] == '\0')
        {
            return 0;
        }
    }
}
*/
