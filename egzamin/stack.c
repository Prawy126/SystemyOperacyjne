#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(void) {
    struct rlimit rl;
    
    if (getrlimit(RLIMIT_STACK, &rl) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }
    
    printf("Maksymalny rozmiar stosu (miękki limit): %ld bajtów\n", (long)rl.rlim_cur);
    printf("Maksymalny rozmiar stosu (twardy limit): %ld bajtów\n", (long)rl.rlim_max);
    printf("Bieżący rozmiar stosu (użycie) nie jest bezpośrednio dostępny programowo.\n");
    
    return 0;
}
