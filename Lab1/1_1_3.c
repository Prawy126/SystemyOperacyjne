#include <stdio.h>
#include <stdlib.h>

int main() {
    char napis[20];
    scanf("%19[^\n]", napis);  // Ogranicza odczytywanie znaków do 19 znaków bez znaku końca linii
    printf("%s", napis);

    return 0;
}
