#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifoPath = "myfifo";

    // Otwarcie FIFO do odczytu. To wywołanie będzie blokować, dopóki jakiś proces nie otworzy FIFO do zapisu.
    int fd = open(fifoPath, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Odczytano: %s\n", buffer);
    } else if (n == 0) {
        printf("Koniec danych (EOF).\n");
    } else {
        perror("read");
    }
    close(fd);
    return 0;
}
