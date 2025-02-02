#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int globalVar;

int main() {
    int localVar = 5;
    int *heapVar = (int *)malloc(sizeof(int));

    printf("Kod programu: %p\n", (void *)main);
    printf("Zmienne globalne: %p\n", (void *)&globalVar);
    printf("Sterta: %p\n", (void *)heapVar);
    printf("Stos: %p\n", (void *)&localVar);

    free(heapVar);
    return 0;
}
