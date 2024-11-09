section .data
    child_msg db "This is the child process. PID: "
    child_msg_len equ $ - child_msg

    parent_msg db "This is the parent process. PID: "
    parent_msg_len equ $ - parent_msg

    child_pid_msg db ", Child PID: "
    child_pid_msg_len equ $ - child_pid_msg

    new_line db 0x0a ; ASCII value for newline

section .bss
    pid resq 1      ; Space for child's PID (moved before buf)
    buf resb 20     ; Buffer for storing PID as string

section .text
    global _start

_start:
    ; Call fork
    mov eax, 57          ; Syscall number for fork
    syscall

    ; Check the return value of fork (child or parent)
    test rax, rax
    jz child_process     ; If result is 0, it's the child process

    ; Parent process code
    mov [pid], rax       ; Save child's PID in variable pid
    mov rdi, 1           ; File descriptor 1 (stdout)
    mov rsi, parent_msg  ; Address of parent message
    mov rdx, parent_msg_len ; Length of parent message
    mov rax, 1           ; Syscall number for write
    syscall              ; Print parent message

    ; Display parent's PID
    mov rax, 39          ; Syscall number for getpid
    syscall
    mov rdi, rax         ; Pass parent's PID to rdi
    call print_int       ; Call print_int function

    ; Display ", Child PID: "
    mov rdi, 1           ; File descriptor 1 (stdout)
    mov rsi, child_pid_msg ; Separator
    mov rdx, child_pid_msg_len ; Length of separator
    mov rax, 1           ; Syscall number for write
    syscall              ; Print separator

    ; Display child's PID
    mov rax, [pid]       ; Load child's PID
    mov rdi, rax         ; Pass child's PID to rdi
    call print_int       ; Call print_int function

    ; Display new line
    mov rdi, 1           ; File descriptor 1 (stdout)
    mov rsi, new_line    ; Newline character
    mov rdx, 1           ; Length of newline character (1 byte)
    mov rax, 1           ; Syscall number for write
    syscall              ; Print newline

    ; Wait for child process to finish
    mov rax, 61          ; Syscall number for wait4
    mov rdi, [pid]       ; Child's PID
    mov rsi, 0           ; status = NULL
    mov rdx, 0           ; options = 0
    mov r10, 0           ; rusage = NULL
    syscall

    jmp exit             ; Proceed to exit

child_process:
    ; Child process code
    mov rdi, 1
    mov rsi, child_msg
    mov rdx, child_msg_len
    mov rax, 1
    syscall

    ; Display child's PID
    mov rax, 39          ; Syscall number for getpid
    syscall
    mov rdi, rax         ; Pass child's PID to rdi
    call print_int       ; Call print_int function

    ; Display new line
    mov rdi, 1           ; File descriptor 1 (stdout)
    mov rsi, new_line    ; Newline character
    mov rdx, 1           ; Length of newline character (1 byte)
    mov rax, 1           ; Syscall number for write
    syscall

exit:
    ; Exit program
    mov rax, 60          ; Syscall number for exit
    mov rdi, 0           ; Exit code 0 (success)
    syscall

print_int:
    ; Convert number in rdi to string
    mov rax, rdi         ; Place number to convert in rax
    mov rcx, 10          ; Set base (10) for decimal conversion
    lea rdi, [buf + 20]  ; Set pointer to end of buffer
    mov byte [rdi], 0    ; Add null terminator at the end of buffer

print_int_loop:
    dec rdi
    xor rdx, rdx         ; Clear rdx
    div rcx              ; Divide rax by 10
    add dl, '0'          ; Convert digit to ASCII
    mov [rdi], dl        ; Store digit in buffer
    test rax, rax        ; Check if rax is zero
    jnz print_int_loop   ; If not, continue loop

    ; Print the number
    mov rsi, rdi         ; Set rsi to start of processed string
    mov rdx, buf + 20    ; Set rdx to end of buffer
    sub rdx, rsi         ; Calculate length of the string
    mov rax, 1           ; Syscall number for write
    mov rdi, 1           ; File descriptor 1 (stdout)
    syscall
    ret
