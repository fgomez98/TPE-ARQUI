
GLOBAL _cli
GLOBAL _sti
GLOBAL picMasterMask
GLOBAL picSlaveMask
GLOBAL haltcpu
GLOBAL _hlt

GLOBAL rip
GLOBAL stack
GLOBAL getStack

GLOBAL _irq00Handler
GLOBAL _irq01Handler
GLOBAL _irq02Handler
GLOBAL _irq03Handler
GLOBAL _irq04Handler
GLOBAL _irq05Handler

GLOBAL _exception0Handler
GLOBAL _exceptionInvalidOpcodeHandler
GLOBAL dir
GLOBAL stack
GLOBAL getStack
EXTERN irqDispatcher
EXTERN exceptionDispatcher

SECTION .text

%macro pushState 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro

%macro popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

%macro irqHandlerMaster 1

	pushState


	mov rdi, %1 ; pasaje de parametro
	mov rsi, rsp ; paso como segundo parametro la direccion del stack en el que estan pusheados todos los registros
	call irqDispatcher

	; signal pic EOI (End of Interrupt)
	mov al, 20h
	out 20h, al

	popState
	iretq
%endmacro



%macro exceptionHandler 1

	pushState




	mov rdi, %1 ; pasaje de parametro
	mov rsi, rsp ; paso como segundo parametro la direccion del stack en el que estan pusheados todos los registros
	call exceptionDispatcher


	popState

	mov rdi, [rip]
	mov qword [rsp] , rdi
	mov rdi, [stack]
	mov qword [rsp + 3 * 8], rdi

	;mov qword [rsp],  400000h; estoy pisando la direccion de retorno para que la exception no se quede en un loop
	iretq
%endmacro


_hlt:
	sti
	hlt
	ret

_cli:
	cli
	ret


_sti:
	sti
	ret

picMasterMask:
	push rbp
    mov rbp, rsp
    mov ax, di
    out	21h,al
    pop rbp
    retn

picSlaveMask:
	push    rbp
    mov     rbp, rsp
    mov     ax, di  ; ax = mascara de 16 bits
    out	0A1h,al
    pop     rbp
    retn


;8254 Timer (Timer Tick)
_irq00Handler:
	irqHandlerMaster 0

;Keyboard
_irq01Handler:
	irqHandlerMaster 1

;Cascade pic never called
_irq02Handler:
	irqHandlerMaster 2

;Serial Port 2 and 4
_irq03Handler:
	irqHandlerMaster 3

;Serial Port 1 and 3
_irq04Handler:
	irqHandlerMaster 4

;USB
_irq05Handler:
	irqHandlerMaster 5


;Zero Division Exception
_exception0Handler:
	exceptionHandler 0

;Invalid Opcode handler
_exceptionInvalidOpcodeHandler:
	exceptionHandler 1

haltcpu:
	cli
	hlt
	ret

getStack:
	mov rax, rsp
	ret

SECTION .bss
	aux resq 1
	rip resq 1
	stack resq 1
