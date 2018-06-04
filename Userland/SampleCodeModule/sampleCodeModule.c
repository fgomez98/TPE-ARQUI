#include <stdint.h>
#include <stdarg.h>
#include"stdio.h"
#include "systemCall.h"
#define WRITE 1
#define READ 0
#define STDOUT 1
#define STDIN 0
#define CLEAR 0


//extern void systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);

void printf(char* fmt, ...);

int main() {
  printf("Loading shell....\n");

  initializeShell();

	return 0;
}
