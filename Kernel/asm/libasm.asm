GLOBAL cpuVendor
GLOBAL getYResolution
GLOBAL getXResolution

section .text

getXResolution:
	push rbp
	mov rbp, rsp

	mov rax, 0
	in al, 0x5084
	
	mov rsp, rbp
	pop rbp
	ret

getYResolution:
	push rbp
	mov rbp, rsp

	mov rax, 0
	in al, 0x5086
	
	mov rsp, rbp
	pop rbp
	ret		

cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret
