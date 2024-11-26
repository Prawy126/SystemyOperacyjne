#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Funkcja sprawdzająca, czy plik jest plikiem tekstowym
int isTextFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (!isascii(ch)) {
            fclose(file);
            return 0; // Plik zawiera znak spoza zakresu ASCII
        }
    }

    fclose(file);
    return 1; // Wszystkie znaki są w zakresie ASCII
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (isTextFile(argv[1])) {
        printf("Plik %s jest plikiem tekstowym.\n", argv[1]);
    } else {
        printf("Plik %s nie jest plikiem tekstowym.\n", argv[1]);
    }

    return 0;
}
