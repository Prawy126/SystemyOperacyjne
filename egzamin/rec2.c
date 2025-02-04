#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile int count = 0;  // licznik rekurencji

void handle_sigsegv(int sig) {
    printf("Otrzymano sygnał %d (prawdopodobnie przepełnienie stosu) przy głębokości: %d\n", sig, count);
    exit(EXIT_FAILURE);
}

void rec() {
    count++;
    rec();  // rekurencyjne wywołanie
}

int main(void) {
    // Ustawienie handlera sygnału SIGSEGV
    signal(SIGSEGV, handle_sigsegv);
    rec();
    return 0;
}
