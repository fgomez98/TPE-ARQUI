#include "stdlib.h"
#include "stdio.h"

extern void systemCall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6);

int atoi(char * str){
  int res = 0;
  int sign = 1; //positive
  int i = 0;

  if(str[0] == '-'){
    sign = -1;
    i = 1;
  }

  for(; str[i] != '\0'; i++){
    res = res*10 + str[i] - '0';
  }

  return sign*res;
}

int isNum(char c){
  return (c >= '0' && c <= '9');
}

int isAlpha(char c){
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
