#include <stdio.h>

int main() {
    if (feof(stdin)) {
        printf("Strumien wejsciowy jest pusty.\n");
    } else {
        printf("Strumien wejsciowy nie jest pusty.\n");
    }
    return 0;
}