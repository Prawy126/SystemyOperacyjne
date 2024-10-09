#include <stdlib.h>
#include <stdio.h>

void zmiana(int *a){
    *a = 10;
    //printf("W trakcie:%d", *a);
}

int main(){
    int a = 1;
    //int *wskaznik = &a;
    //printf("Adres: %d\n", &a);
    zmiana(&a);
    printf("\nPo:%d\n", a);
    return 0;
}