#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Proces dziecka: PID = %d, PPID = %d\n", getpid(), getppid());
    } else {
        printf("Proces rodzica: PID = %d, PPID = %d\n", getpid(), getppid());
    }

    return 0;
}
