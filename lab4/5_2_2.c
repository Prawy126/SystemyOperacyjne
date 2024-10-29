#include <stdio.h>
#include <ctype.h>

int countWords2(FILE *fp) {
    int count = 0;
    int inWord = 0;  // Zmienna pomocnicza, która określa, czy jesteśmy w środku słowa
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch)) {
            inWord = 0;  // Jeśli natrafimy na znak biały, oznacza to koniec słowa
        } else if (!inWord) {
            inWord = 1;  // Jeśli nie jesteśmy w słowie i pojawia się znak niebędący białym
            count++;     // oznacza to początek nowego słowa, więc zwiększamy licznik
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uzycie: %s <nazwa_pliku>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Nie mozna otworzyc pliku");
        return 1;
    }

    int wordCount = countWords2(fp);
    printf("Liczba slow: %d\n", wordCount);

    fclose(fp);
    return 0;
}
