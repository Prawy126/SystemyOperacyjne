#include <stdio.h>
#include <stdlib.h>

void copyFile(const char *sourceFile, const char *destFile) {
    FILE *source, *dest;
    char ch;

    // Otwieramy plik źródłowy do odczytu
    source = fopen(sourceFile, "r");
    if (source == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Otwieramy plik docelowy do zapisu
    dest = fopen(destFile, "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(source);
        exit(EXIT_FAILURE);
    }

    // Kopiujemy zawartość pliku źródłowego do pliku docelowego
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully.\n");

    // Zamykamy pliki
    fclose(source);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    copyFile(argv[1], argv[2]);

    return 0;
}
