#include <stdlib.h>
#include <stdio.h>

int fib_tail_recursive(int n, int a, int b) {
    if (n == 0) {
        return a;
    }
    return fib_tail_recursive(n-1, b, a + b);
}

int fibo_sym(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibo_sym(n-1) + fibo_sym(n-2);
}

int fibo_tail(int n) {
    return fib_tail_recursive(n, 0, 1);
}

void multiply(int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n) {
    if (n == 0 || n == 1) return;
    int M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0) multiply(F, M);
}

int fibo_matrix(int n) {
    int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0) return 0;
    power(F, n - 1);
    return F[0][0];
}


int fibo_divide_conquer(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int k = (n % 2 == 0) ? n / 2 : (n + 1) / 2;

    int fib_k = fibo_divide_conquer(k);
    int fib_k_minus_1 = fibo_divide_conquer(k - 1);

    if (n % 2 == 0) {
        return fib_k * (2 * fib_k_minus_1 + fib_k);
    } else {
        return fib_k * fib_k + fib_k_minus_1 * fib_k_minus_1;
    }
}


int main() {
    int n = 4;
    printf("fibo_tail(%d) = %d\n", n, fibo_tail(n));
    printf("fibo_sym(%d) = %d\n", n, fibo_sym(n));
    printf("fibo_matrix(%d) = %d\n", n, fibo_matrix(n));
    printf("fibo_divide_conquer(%d) = %d\n", n, fibo_divide_conquer(n));
    return 0;
}
