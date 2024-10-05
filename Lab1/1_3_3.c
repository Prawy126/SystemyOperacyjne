#include <stdlib.h>
#include <stdio.h>

/*
 * ramkę należy przesunać n - 2 czyli 2 razy dla n = 4
 *
 * analiza fibo3(4)
 * fibo3(4) = ?
 * r1 = 1
 * pom = 0, r0 = 0
 * 4 >= 1 True
 * pom = r0 = 0
 * r0 = r1 = 1
 * r1 = r0 + pom = 1 + 0
 * n - 1 = 3
 * 3 >= 1 True
 * pom = r0 = 1
 * r0 = r1 = 1
 * r1 = r0 + pom = 1 + 1
 * n - 1 = 2
 * 2 >= 1 True
 * pom = r0 = 1
 * r0 = r1 = 2
 * r1 = r0 + pom = 2 + 1 = 3
 * n - 1 = 1
 * 1 >= 1 True
 * pom = r0 = 2
 * r0 = r1 = 3
 * r1 = r0 + pom = 3 + 2 = 5
 * n - 1 = 0
 * 0 >= 1 False
 * return r1 = 5
 */

int fibo3(int n) {
    int r1 = 1;
    int pom, r0;
    while(n>=1) {
        pom = r0;
        r0 = r1;
        r1 = r0 + pom;
        n--;
    }
    return r1;
}

int main() {
    int n = 4;
    printf("fibo3(%d) = %d", n, fibo3(n));
    return 0;
}