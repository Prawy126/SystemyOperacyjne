#include <stdio.h>
#include <stdlib.h>

void copy(const char *addr1, const char *addr2) {
    FILE *source, *destination;
    char buffer[1024];  // Bufor o rozmiarze 1 KB dla kopiowania danych
    size_t bytesRead;

    // Otwieranie pliku źródłowego w trybie "read binary"
    source = fopen(addr1, "rb");
    if (source == NULL) {
        perror("Nie można otworzyc pliku zrodłowego");
        exit(EXIT_FAILURE);
    }

    // Otwieranie pliku docelowego w trybie "write binary"
    destination = fopen(addr2, "wb");
    if (destination == NULL) {
        perror("Nie mozna otworzyc pliku docelowego");
        fclose(source);
        exit(EXIT_FAILURE);
    }

    // Czytanie danych ze źródła i ich zapisywanie w docelowym pliku
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        if (fwrite(buffer, 1, bytesRead, destination) != bytesRead) {
            perror("Blad podczas zapisywania do pliku docelowego");
            fclose(source);
            fclose(destination);
            exit(EXIT_FAILURE);
        }
    }

    // Zamknięcie plików
    fclose(source);
    fclose(destination);

    printf("Plik skopiowany pomyslnie.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uzycie: %s <plik zrodlowy> <plik docelowy>\n", argv[0]);
        return EXIT_FAILURE;
    }

    copy(argv[1], argv[2]);
    return EXIT_SUCCESS;
}
