#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funkcja do odwracania łańcucha znaków
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void reverseLinesInFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Usuwamy znak nowej linii na końcu linii (jeśli istnieje)
        line[strcspn(line, "\n")] = '\0';

        // Odwracamy kolejność znaków w linii
        reverseString(line);

        // Zapisujemy odwróconą linię do pliku tymczasowego
        fprintf(tempFile, "%s\n", line);
    }

    fclose(file);
    fclose(tempFile);

    // Zamieniamy oryginalny plik z plikiem tymczasowym
    if (remove(fileName) != 0) {
        perror("Error deleting original file");
        exit(EXIT_FAILURE);
    }
    if (rename("temp.txt", fileName) != 0) {
        perror("Error renaming temporary file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    reverseLinesInFile(argv[1]);

    printf("Lines in file %s have been reversed.\n", argv[1]);
    return 0;
}
