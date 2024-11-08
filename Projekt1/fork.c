#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Wywołanie funkcji fork
    pid = fork();

    if (pid < 0) { // Błąd przy wywołaniu fork
        perror("fork failed");
        return 1;
    } else if (pid == 0) { // Proces dziecka
        printf("This is the child process. PID: %d\n", getpid());
    } else { // Proces rodzica
        printf("This is the parent process. PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}
