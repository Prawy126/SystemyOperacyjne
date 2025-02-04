#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifoPath = "myfifo";

    // Otwarcie FIFO do zapisu. Jeśli nie ma czytelnika, open() będzie blokowało.
    int fd = open(fifoPath, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    const char *msg = "Wiadomość z programu fwriter";
    if (write(fd, msg, strlen(msg)) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Wiadomość wysłana.\n");
    close(fd);
    return 0;
}
