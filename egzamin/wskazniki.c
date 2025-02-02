#include <stdio.h>

int main() {
    int x = 10;
    int *ptr = &x;

    printf("Wartość x: %d\n", x);
    printf("Adres x: %p\n", &x);
    printf("Wartość wskaźnika ptr: %p\n", ptr);
    printf("Wartość wskazywana przez ptr: %d\n", *ptr);

    *ptr = 20;  // Zmiana wartości x przez wskaźnik
    printf("Nowa wartość x: %d\n", x);

    return 0;
}
