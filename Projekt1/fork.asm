section .data
    child_msg db "This is the child process. PID: ", 0xa
    child_msg_len equ $ - child_msg

    parent_msg db "This is the parent process. PID: ", 0xa, "Child PID: "
    parent_msg_len equ $ - parent_msg

    new_line db 0x0a ; ASCII value for newline

section .bss
    buf resb 20 ; Bufor do przechowywania PID jako string
    pid resq 1  ; Przestrzeń na PID dziecka

section .text
    global _start

_start:
    ; Wywołanie fork
    mov eax, 57          ; Numer syscall dla fork
    syscall

    ; Sprawdź wartość zwróconą przez fork (czy to dziecko czy rodzic)
    test rax, rax
    jz child_process     ; Jeśli wynik to 0, to proces dziecka

    ; Kod dla procesu rodzica
    mov [pid], rax       ; Zapisz PID dziecka w zmiennej pid
    mov rdi, 1           ; Deskryptor pliku 1 (stdout)
    mov rsi, parent_msg  ; Adres wiadomości rodzica
    mov rdx, parent_msg_len ; Długość wiadomości rodzica
    mov rax, 1           ; Numer syscall dla write
    syscall              ; Wywołanie syscall - wydrukowanie wiadomości

    ; Wyświetlenie PID procesu rodzica
    mov rax, 39          ; Numer syscall dla getpid
    syscall
    mov rdi, rax         ; Przekazanie PID rodzica do rdi
    call print_int       ; Wywołanie funkcji print_int

    ; Wyświetlenie PID dziecka
    mov rdi, 1           ; Deskryptor pliku 1 (stdout)
    mov rsi, ": "        ; Separator
    mov rdx, 2           ; Długość separatora
    mov rax, 1           ; Numer syscall dla write
    syscall              ; Wywołanie syscall - drukowanie separatora

    mov rax, [pid]       ; Załaduj PID dziecka
    mov rdi, rax         ; Przekazanie PID dziecka do rdi
    call print_int       ; Wywołanie funkcji print_int

    ; Wyświetlenie nowej linii
    mov rsi, new_line    ; Znak nowej linii
    mov rdx, 1           ; Długość znaku nowej linii (1 bajt)
    mov rax, 1           ; Numer syscall dla write
    mov rdi, 1           ; Deskryptor pliku 1 (stdout)
    syscall              ; Wywołanie syscall

    jmp exit             ; Przejdź do zakończenia programu

child_process:
    ; Kod dla procesu dziecka
    mov rdi, 1
    mov rsi, child_msg
    mov rdx, child_msg_len
    mov rax, 1
    syscall

    ; Wyświetlenie PID dziecka
    mov rax, 39          ; Numer syscall dla getpid
    syscall
    mov rdi, rax         ; Przekazanie PID dziecka do rdi
    call print_int       ; Wywołanie funkcji print_int

    ; Wyświetlenie nowej linii
    mov rsi, new_line    ; Znak nowej linii
    mov rdx, 1           ; Długość znaku nowej linii (1 bajt)
    mov rax, 1           ; Numer syscall dla write
    mov rdi, 1           ; Deskryptor pliku 1 (stdout)
    syscall

exit:
    ; Zakończenie programu
    mov rax, 60          ; Numer syscall dla exit
    mov rdi, 0           ; Kod wyjścia 0 (sukces)
    syscall

print_int:
    ; Konwersja liczby w rdi na string
    mov rax, rdi         ; Umieść liczbę do konwersji w rax
    mov rcx, 10          ; Ustaw podstawę (10) do konwersji dziesiętnej
    lea rdi, [buf + 20]  ; Ustaw wskaźnik na koniec bufora
    mov byte [rdi], 0    ; Dodaj null na końcu bufora

print_int_loop:
    dec rdi
    xor rdx, rdx         ; Wyczyść rdx
    div rcx              ; Podziel rax przez 10
    add dl, '0'          ; Zamień cyfrę na ASCII
    mov [rdi], dl        ; Zapisz cyfrę w buforze
    test rax, rax        ; Sprawdź, czy rax jest równy 0
    jnz print_int_loop   ; Jeśli nie, kontynuuj pętlę

    ; Drukowanie liczby
    mov rsi, rdi         ; Ustaw rsi na początek przetworzonego ciągu
    mov rdx, buf + 20    ; Ustaw rdx na koniec bufora
    sub rdx, rsi         ; Oblicz długość ciągu znaków
    mov rax, 1           ; Numer syscall dla write
    mov rdi, 1           ; Deskryptor pliku 1 (stdout)
    syscall
    ret
