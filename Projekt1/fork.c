#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid; // Zmienna do przechowywania PID procesu

    // Wywołanie funkcji fork
    pid = fork();

    if (pid < 0) { // Błąd podczas tworzenia procesu
        perror("fork failed");
        return 1;
    } else if (pid == 0) { // Kod procesu dziecka
        printf("This is the child process. PID: %d\n", getpid());
    } else { // Kod procesu rodzica
        // Czekaj na zakończenie procesu dziecka
        waitpid(pid, NULL, 0);

        // Wyświetl komunikat rodzica z PID dziecka
        printf("This is the parent process. PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0; // Zakończ program
}
