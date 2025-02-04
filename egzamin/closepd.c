#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Zamykamy uchwyt do odczytu – nie ma procesu odczytującego
    close(fd[0]);

    // Ustawiamy ignorowanie sygnału SIGPIPE, żeby program nie został zakończony
    signal(SIGPIPE, SIG_IGN);

    // Próba zapisu do potoku bez odbierającego procesu
    ssize_t ret = write(fd[1], "Test", 4);
    if (ret == -1) {
        perror("write");
        printf("Zapis do potoku bez procesów odczytujących powoduje błąd (EPIPE).\n");
    } else {
        printf("Write succeeded unexpectedly.\n");
    }
    return 0;
}
