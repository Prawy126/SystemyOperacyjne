#include <stdio.h>
#include <stdlib.h>

/*
 * ramkę należy przsunąć według wzoru n-3
 *
 * analiza wywołań
 *
 * fibo2(4) = ?
 * r0 = 0
 * r1 = 0
 * r2 = 1
 * 4 >= 1 True
 * r0 = r1 = 0
 * r1 = r2 = 1
 * r2 = r1 + r0 = 1 + 0
 * n - 1 = 3
 * 3 >= 1 True
 * r0 = r1 = 1
 * r1 = r2 = 1
 * r2 = r1 + r0 = 1 + 1 = 2
 * n - 1 = 2
 * 2 >= 1 True
 * r0 = r1 = 1
 * r1 = r2 = 2
 * r2 = r0 + r1 = 1 + 2 = 3
 * n - 1 = 1
 * 1 >= 1 True
 * r0 = r1 = 2
 * r1 = r2 = 3
 * r2 = r1 + r0 = 2 + 3 = 5
 * n - 1 = 0
 * 0 >= 1 False
 *
 * return r2 = 5
 */

int fibo2(int n) {
   int r0, r1, r2;
    r0 = 0;
    r1 = 0;
    r2 = 1;

    while (n >= 1) {
        r0 = r1;
        r1 = r2;
        r2 = r0 + r1;
        n --;
    }
    return r2;

}

int main() {
    int n = 4;
    printf("fibo(%d) = %d\n", n, fibo2(n));
    return 0;
}