GLOBAL probandoExcepcion

section .text

probandoExcepcion:
  mov rax, 5
  mov rbx, 6
  int 6h
  ret