section .data
    child_msg db "This is the child process. PID: " ; Wiadomość dla procesu dziecka
    child_msg_len equ $ - child_msg               ; Długość wiadomości dziecka

    parent_msg db "This is the parent process. PID: " ; Wiadomość dla procesu rodzica
    parent_msg_len equ $ - parent_msg                 ; Długość wiadomości rodzica

    child_pid_msg db ", Child PID: " ; Separator między PID rodzica a PID dziecka
    child_pid_msg_len equ $ - child_pid_msg ; Długość separatora

    new_line db 0x0a ; Znak nowej linii (ASCII)

section .bss
    pid resq 1  ; Przechowuje PID dziecka
    buf resb 20 ; Bufor dla konwersji liczby na tekst

section .text
    global _start

_start:
    mov eax, 57          ; Załaduj numer syscall dla fork do rejestru eax
    syscall              ; Wykonaj syscall (tworzy nowy proces)

    test rax, rax        ; Sprawdź wynik fork (czy rax jest 0)
    jz child_process     ; Skocz do child_process, jeśli wynik to 0 (proces dziecka)

    mov [pid], rax       ; Zapisz PID dziecka w zmiennej pid

    mov rax, 61          ; Załaduj numer syscall dla wait4 do rejestru eax
    mov rdi, [pid]       ; Ustaw PID dziecka w rdi
    mov rsi, 0           ; Ustaw wskaźnik na status jako NULL
    mov rdx, 0           ; Ustaw opcje jako 0
    mov r10, 0           ; Ustaw rusage jako NULL
    syscall              ; Wykonaj syscall (czeka na zakończenie procesu dziecka)

    mov rdi, 1           ; Deskryptor pliku (stdout)
    mov rsi, parent_msg  ; Adres komunikatu rodzica
    mov rdx, parent_msg_len ; Długość komunikatu rodzica
    mov rax, 1           ; Numer syscall dla write
    syscall              ; Wyświetl komunikat rodzica

    mov rax, 39          ; Załaduj numer syscall dla getpid do rejestru eax
    syscall              ; Pobierz PID procesu rodzica
    mov rdi, rax         ; Przekaż PID do rdi
    call print_int       ; Wywołaj funkcję konwersji i wyświetlenia liczby

    mov rdi, 1           ; Deskryptor pliku (stdout)
    mov rsi, child_pid_msg ; Separator dla PID dziecka
    mov rdx, child_pid_msg_len ; Długość separatora
    mov rax, 1           ; Numer syscall dla write
    syscall              ; Wyświetl separator

    mov rax, [pid]       ; Załaduj PID dziecka z pamięci
    mov rdi, rax         ; Przekaż PID do rdi
    call print_int       ; Wywołaj funkcję konwersji i wyświetlenia liczby

    mov rdi, 1           ; Deskryptor pliku (stdout)
    mov rsi, new_line    ; Znak nowej linii
    mov rdx, 1           ; Długość znaku nowej linii
    mov rax, 1           ; Numer syscall dla write
    syscall              ; Wyświetl nową linię

    jmp exit             ; Skocz do sekcji exit

child_process:
    mov rdi, 1           ; Deskryptor pliku (stdout)
    mov rsi, child_msg   ; Adres komunikatu dziecka
    mov rdx, child_msg_len ; Długość komunikatu dziecka
    mov rax, 1           ; Numer syscall dla write
    syscall              ; Wyświetl komunikat dziecka

    mov rax, 39          ; Załaduj numer syscall dla getpid
    syscall              ; Pobierz PID procesu dziecka
    mov rdi, rax         ; Przekaż PID do rdi
    call print_int       ; Wywołaj funkcję konwersji i wyświetlenia liczby

    mov rdi, 1           ; Deskryptor pliku (stdout)
    mov rsi, new_line    ; Znak nowej linii
    mov rdx, 1           ; Długość znaku nowej linii
    mov rax, 1           ; Numer syscall dla write
    syscall              ; Wyświetl nową linię

exit:
    mov rax, 60          ; Załaduj numer syscall dla exit
    mov rdi, 0           ; Kod wyjścia (0 - sukces)
    syscall              ; Zakończ proces

print_int:
    mov rax, rdi         ; Przenieś liczbę do rax
    mov rcx, 10          ; Ustaw bazę dziesiętną
    lea rdi, [buf + 20]  ; Ustaw wskaźnik na koniec bufora
    mov byte [rdi], 0    ; Dodaj znak null na końcu

print_int_loop:
    dec rdi              ; Przesuń wskaźnik w lewo
    xor rdx, rdx         ; Wyzeruj rdx (reszta dzielenia)
    div rcx              ; Podziel przez 10
    add dl, '0'          ; Zamień cyfrę na ASCII
    mov [rdi], dl        ; Zapisz cyfrę w buforze
    test rax, rax        ; Sprawdź, czy liczba to 0
    jnz print_int_loop   ; Jeśli nie, kontynuuj pętlę

    mov rsi, rdi         ; Ustaw wskaźnik na początek ciągu
    mov rdx, buf + 20    ; Ustaw wskaźnik na koniec bufora
    sub rdx, rsi         ; Oblicz długość ciągu
    mov rax, 1           ; Numer syscall dla write
    mov rdi, 1           ; Deskryptor pliku (stdout)
    syscall              ; Wyświetl ciąg
    ret                  ; Zakończ funkcję

;nasm -f elf64 ASMwrite.asm -o ASMwrite.o

;ld ASMwrite.o -o ASMwrite
