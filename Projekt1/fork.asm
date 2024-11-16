section .data
    child_msg db "This is the child process. PID: "
    child_msg_len equ $ - child_msg

    parent_msg db "This is the parent process. PID: "
    parent_msg_len equ $ - parent_msg

    child_pid_msg db ", Child PID: "
    child_pid_msg_len equ $ - child_pid_msg

    new_line db 0x0a ; ASCII value for newline

section .bss
    pid resq 1      ; Space for child's PID
    buf resb 20     ; Buffer for storing PID as string

section .text
    global _start

_start:
    ; Wywołanie fork
    mov eax, 57          ; Numer syscall dla fork
    syscall

    ; Sprawdzenie wyniku fork (dziecko czy rodzic)
    test rax, rax
    jz child_process     ; Jeśli wynik to 0, to proces dziecka

    ; Kod procesu rodzica
    mov [pid], rax       ; Zapisz PID dziecka w zmiennej pid

    ; Czekaj na zakończenie procesu dziecka
    mov rax, 61          ; Numer syscall dla wait4
    mov rdi, [pid]       ; PID dziecka
    mov rsi, 0           ; status = NULL
    mov rdx, 0           ; options = 0
    mov r10, 0           ; rusage = NULL
    syscall

    ; Teraz rodzic wykonuje swoje operacje wyjścia
    mov rdi, 1           ; Deskryptor pliku 1 (stdout)
    mov rsi, parent_msg  ; Adres komunikatu rodzica
    mov rdx, parent_msg_len ; Długość komunikatu rodzica
    mov rax, 1           ; Numer syscall dla write
    syscall              ; Wyświetl komunikat rodzica

    ; Wyświetl PID rodzica
    mov rax, 39          ; Numer syscall dla getpid
    syscall
    mov rdi, rax         ; Przekaż PID rodzica do rdi
    call print_int       ; Wywołaj funkcję print_int

    ; Wyświetl ", Child PID: "
    mov rdi, 1           ; Deskryptor pliku 1 (stdout)
    mov rsi, child_pid_msg ; Separator
    mov rdx, child_pid_msg_len ; Długość separatora
    mov rax, 1           ; Numer syscall dla write
    syscall              ; Wyświetl separator

    ; Wyświetl PID dziecka
    mov rax, [pid]       ; Załaduj PID dziecka
    mov rdi, rax         ; Przekaż PID dziecka do rdi
    call print_int       ; Wywołaj funkcję print_int

    ; Wyświetl nową linię
    mov rdi, 1           ; Deskryptor pliku 1 (stdout)
    mov rsi, new_line    ; Znak nowej linii
    mov rdx, 1           ; Długość znaku nowej linii (1 bajt)
    mov rax, 1           ; Numer syscall dla write
    syscall              ; Wyświetl nową linię

    jmp exit             ; Przejdź do wyjścia

child_process:
    ; Kod procesu dziecka
    mov rdi, 1
    mov rsi, child_msg
    mov rdx, child_msg_len
    mov rax, 1
    syscall

    ; Wyświetl PID dziecka
    mov rax, 39          ; Numer syscall dla getpid
    syscall
    mov rdi, rax         ; Przekaż PID dziecka do rdi
    call print_int       ; Wywołaj funkcję print_int

    ; Wyświetl nową linię
    mov rdi, 1           ; Deskryptor pliku 1 (stdout)
    mov rsi, new_line    ; Znak nowej linii
    mov rdx, 1           ; Długość znaku nowej linii (1 bajt)
    mov rax, 1           ; Numer syscall dla write
    syscall

exit:
    ; Zakończ program
    mov rax, 60          ; Numer syscall dla exit
    mov rdi, 0           ; Kod wyjścia 0 (sukces)
    syscall

print_int:
    ; Konwersja liczby w rdi na ciąg znaków
    mov rax, rdi         ; Umieść liczbę do konwersji w rax
    mov rcx, 10          ; Ustaw bazę (10) dla konwersji dziesiętnej
    lea rdi, [buf + 20]  ; Ustaw wskaźnik na koniec bufora
    mov byte [rdi], 0    ; Dodaj znak null na końcu bufora

print_int_loop:
    dec rdi
    xor rdx, rdx         ; Wyzeruj rdx
    div rcx              ; Podziel rax przez 10
    add dl, '0'          ; Konwertuj cyfrę na ASCII
    mov [rdi], dl        ; Zapisz cyfrę w buforze
    test rax, rax        ; Sprawdź, czy rax jest zerem
    jnz print_int_loop   ; Jeśli nie, kontynuuj pętlę

    ; Wyświetl liczbę
    mov rsi, rdi         ; Ustaw rsi na początek przetworzonego ciągu
    mov rdx, buf + 20    ; Ustaw rdx na koniec bufora
    sub rdx, rsi         ; Oblicz długość ciągu
    mov rax, 1           ; Numer syscall dla write
    mov rdi, 1           ; Deskryptor pliku 1 (stdout)
    syscall
    ret
