section .data
    child_msg db "This is the child process. PID: ", 0xa
    child_msg_len equ $-child_msg
    parent_msg db "This is the parent process. PID: ", 0xa, "Child PID: "
    parent_msg_len equ $-parent_msg
    pid_msg db " Child PID: ", 0xa
    pid_len equ $-pid_msg
    new_line db 0x0a ; ASCII value for newline

section .bss
    buf resb 20 ; Bufor do przechowywania PID jako string

section .text
    global _start

_start:
    ; Fork a new process
    mov eax, 57 ; system call number for fork
    syscall

    ; Check the return value in rax
    test rax, rax
    jz child_process

    ; Parent process
    mov [buf], rax ; save the child's PID
    mov rdi, 1 ; file descriptor 1 (stdout)
    mov rsi, parent_msg
    mov rdx, parent_msg_len
    mov rax, 1 ; system call number for write
    syscall

    ; Print the parent's PID
    mov rax, 39 ; syscall number for getpid
    syscall
    mov rdi, rax
    call print_int

    ; Print the child's PID message
    mov rdi, 1 ; file descriptor 1 (stdout)
    mov rsi, pid_msg
    mov rdx, pid_len
    mov rax, 1
    syscall

    ; Print the child's PID
    mov rax, [buf] ; load the child's PID into rax
    mov rdi, rax
    call print_int

    ; Print a newline
    mov rdi, 1
    mov rsi, new_line
    mov rdx, 1
    mov rax, 1
    syscall

    jmp exit

child_process:
    ; Child process
    mov rdi, 1
    mov rsi, child_msg
    mov rdx, child_msg_len
    mov rax, 1
    syscall

    ; Print the child's PID
    mov rax, 39 ; syscall number for getpid
    syscall
    mov rdi, rax
    call print_int

    ; Print a newline
    mov rdi, 1
    mov rsi, new_line
    mov rdx, 1
    mov rax, 1
    syscall

exit:
    ; Exit the process
    mov rax, 60 ; system call number for exit
    mov rdi, 0 ; exit code 0 (success)
    syscall

print_string:
    mov rax, 1 ; syscall number for write
    mov rdi, 1 ; file descriptor 1 (stdout)
    syscall
    ret

print_int:
    ; Konwersja liczby w rdi do string
    mov rax, rdi
    mov rcx, 10
    lea rdi, [buf + 20]
    mov byte [rdi], 0

print_int_loop:
    dec rdi
    xor rdx, rdx
    div rcx
    add dl, '0'
    mov [rdi], dl
    test rax, rax
    jnz print_int_loop

    ; Wydrukowanie liczby
    mov rsi, rdi
    mov rdx, buf + 20
    sub rdx, rsi
    mov rax, 1
    mov rdi, 1
    syscall
    ret
