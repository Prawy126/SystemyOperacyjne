#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char write_msg[] = "Hello, file descriptor!\n";
    char read_buffer[50];
    int fd;

    // Otwieranie pliku do zapisu i odczytu (tworzenie go, jeśli nie istnieje)
    fd = open("example.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        _exit(1);
    }

    // Zapis do pliku za pomocą wywołania systemowego write
    if (write(fd, write_msg, sizeof(write_msg) - 1) == -1) {
        perror("Error writing to file");
        _exit(1);
    }

    // Przesunięcie wskaźnika pliku na początek
    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("Error seeking in file");
        _exit(1);
    }

    // Odczyt z pliku za pomocą wywołania systemowego read
    if (read(fd, read_buffer, sizeof(read_buffer) - 1) == -1) {
        perror("Error reading from file");
        _exit(1);
    }

    // Dodanie znaku null do odczytanego ciągu
    read_buffer[sizeof(write_msg) - 1] = '\0';

    // Wyświetlenie odczytanych danych
    printf("Read from file: %s", read_buffer);

    // Zamknięcie pliku
    if (close(fd) == -1) {
        perror("Error closing file");
        _exit(1);
    }

    _exit(0);
}
