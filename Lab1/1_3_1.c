#include <stdlib.h>
#include <stdio.h>
/*
 *  fibo(4) = 5
 *  n = 4
 *  if 4 <= 1 false
 *  fibo(3)+fibo(2) = ? = 3 + 2 = 5
 *
 *  fibo(3) = 3
 *  n = 3
 *  3 <= 1 false
 *  fibo(2) + fibo(1) = ? = 2 + 1 = 3
 *
 *  fibo(2) = 2
 *  n = 2
 *  2 <= 1 false
 *  fibo(1) + fibo(0) = ? = 1 + 1 = 2
 *
 *  fibo(1) = 1
 *  n = 1
 *  1 <= 1  true
 *  return 1
 *
 *  fibo(0) = 1
 *  n = 0
 *  0 <= 1 true
 *  return 1
 */
int fibo1(int n) {
    if (n <= 1) {
        return 1;
    }else {
        return fibo1(n-1) + fibo1(n-2);
    }
}


int main() {
    int n = 4;
    printf("Fibo(%d) = %d\n", n, fibo1(n));
    return 0;
}