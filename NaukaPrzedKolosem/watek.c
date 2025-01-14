#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* watekFunkcja(void* arg){
        printf("Jestem w nowym watku! Arg: %d\n", *((int*)arg));
        return NULL;
}

int main(){
        pthread_t watek;
        int liczba = 123;

        pthread_create(&watek, NULL, watekFunkcja, (void*)&liczba); 

        pthread_join(watek,NULL);

        printf("Koniec programu (watek zakonczyl dzialanie).\n");

        return 0;
}

