#include <stdio.h>
#include <stdlib.h>

int globalVar = 10;  // Sekcja danych

void function(int param) {  
    int localVar = param;  // Stos
    printf("Adres zmiennej lokalnej: %p\n", (void*)&localVar);
}

int main() {
    int *heapVar = (int *)malloc(sizeof(int));  // Alokacja na stercie
    *heapVar = 20;

    printf("Adres funkcji main (kod): %p\n", (void*)main);
    printf("Adres zmiennej globalnej: %p\n", (void*)&globalVar);
    printf("Adres sterty: %p\n", (void*)heapVar);

    function(5);

    free(heapVar);
    return 0;
}
