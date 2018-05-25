GLOBAL _syscall_handler

extern syscall_handler

section .text

;syscall handler esta en kernel.c

_syscall_handler:
	call syscall_handler
	iretq
