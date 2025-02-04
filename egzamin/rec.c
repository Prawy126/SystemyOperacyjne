#include <stdio.h>
#include <stdlib.h>

void rec() {
    rec();  // nieskończona rekurencja prowadząca do przepełnienia stosu
}

int main(void) {
    rec();  
    return 0;
}
