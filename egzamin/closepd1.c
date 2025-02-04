#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Proces potomny: zamykamy koniec zapisu i czekamy 2 sekundy
        close(fd[1]);
        sleep(2);
        // Zakończenie – automatycznie zamknięcie pozostałego uchwytu
        exit(0);
    } else {
        // Proces rodzic: zamykamy koniec zapisu, aby odczyt miał sens
        close(fd[1]);
        char buffer[100];
        // Proces rodzic blokuje się tutaj na read()
        ssize_t n = read(fd[0], buffer, sizeof(buffer));
        if(n == 0) {
            printf("Odczyt z potoku bez procesów zapisujących zwraca EOF (0 bajtów), a nie błąd.\n");
        } else if (n == -1) {
            perror("read");
        } else {
            buffer[n] = '\0';
            printf("Odczytano: %s\n", buffer);
        }
        wait(NULL);
    }
    return 0;
}
