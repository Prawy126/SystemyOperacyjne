#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

void print_addition(int a, int b) {
    int digits_a[22] = {0}, digits_b[22] = {0}, result[23] = {0}, carry[23] = {0};
    int len_a = 0, len_b = 0, max_len = 0;
    int temp_a = a, temp_b = b;
    int i = 0, sum = 0, carry_over = 0;

    while (temp_a > 0) {
        digits_a[len_a++] = temp_a % 10;
        temp_a /= 10;
    }

    while (temp_b > 0) {
        digits_b[len_b++] = temp_b % 10;
        temp_b /= 10;
    }

    max_len = (len_a > len_b ? len_a : len_b);

    for (i = 0; i < max_len; i++) {
        int digit_a = (i < len_a) ? digits_a[i] : 0;
        int digit_b = (i < len_b) ? digits_b[i] : 0;

        sum = digit_a + digit_b + carry_over;
        result[i] = sum % 10;
        carry_over = sum / 10;
        carry[i + 1] = carry_over;  
    }

    if (carry_over > 0) {
        result[max_len] = carry_over;
        max_len++;
    }

    printf(" ");
    for (i = max_len - 1; i > 0; i--) {
        if (carry[i] > 0) {
            printf("%d", carry[i]);
        } else {
            printf(" ");
        }
    }
    printf("\n");

    printf(" ");
    for (i = max_len - 1; i >= 0; i--) {
        if (i < len_a) {
            printf("%d", digits_a[i]);
        } else {
            printf(" ");
        }
    }
    printf("\n");

    printf("+");
    for (i = max_len - 1; i >= 0; i--) {
        if (i < len_b) {
            printf("%d", digits_b[i]);
        } else {
            printf(" ");
        }
    }
    printf("\n");

    printf(" ");
    for (i = 0; i < max_len; i++) {
        printf("-");
    }
    printf("\n");

    printf(" ");
    for (i = max_len - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int a, b;
    bool ba = true, bb = true;

    while (ba || bb) {
        printf("Podaj liczby a i b:\na = ");
        if (scanf("%d", &a) != 1 || a > INT_MAX || a < 0) {
            printf("Niepoprawna wartość dla a. Spróbuj ponownie.\n");
            while(getchar() != '\n'); 
            continue;
        } else {
            ba = false;
        }

        printf("b = ");
        if (scanf("%d", &b) != 1 || b > INT_MAX || b < 0) {
            printf("Niepoprawna wartość dla b. Spróbuj ponownie.\n");
            while(getchar() != '\n'); 
            ba = true; 
        } else {
            bb = false;
        }
    }

    print_addition(a, b);

    return 0;
}
