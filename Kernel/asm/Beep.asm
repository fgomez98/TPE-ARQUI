GLOBAL beep

section .text

beep:
    push rbp
    mov rbp, rsp
    mov al, 0xb6
    out 0x43, al
    mov rax, 0
    mov al, 1193180
    out 0x42, al
    mov al, ah
    out 0x42, al
    in al, 61h
    or al, 0x03
    out 61h, al
    mov rsp, rbp
    pop rbp
    ret
