#include <stdio.h>

void byValue(int num) {
    num = num + 10;
}

void byPointer(int *num) {
    *num = *num + 10;
}

int main() {
    int x = 5;
    byValue(x);
    printf("Po byValue: %d\n", x);  // x się nie zmieni

    byPointer(&x);
    printf("Po byPointer: %d\n", x);  // x się zmieni

    return 0;
}
