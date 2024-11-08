#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_addition(int a, int b) {
    char str_a[20], str_b[20], result[20], carry_str[20];
    int len_a, len_b, len_res, carry = 0;
    int i, j, digit_a, digit_b, sum;

    snprintf(str_a, sizeof(str_a), "%d", a);
    snprintf(str_b, sizeof(str_b), "%d", b);
    len_a = strlen(str_a);
    len_b = strlen(str_b);
    int max_len = (len_a > len_b ? len_a : len_b) + 1;

    // Ensure result and carry_str arrays are empty
    memset(result, 0, sizeof(result));
    memset(carry_str, ' ', sizeof(carry_str));
    carry_str[max_len + 1] = '\0';

    // Perform digit-by-digit addition from the rightmost digit
    for (i = len_a - 1, j = len_b - 1, len_res = max_len - 1; i >= 0 || j >= 0 || carry; i--, j--, len_res--) {
        digit_a = (i >= 0) ? str_a[i] - '0' : 0;
        digit_b = (j >= 0) ? str_b[j] - '0' : 0;

        sum = digit_a + digit_b + carry;
        carry = sum / 10;
        result[len_res] = (sum % 10) + '0';
        if (carry > 0) {
            carry_str[len_res - 1] = '1';  // Shift carry by one position to the left
        }
    }

    // Print carry if there is one
    printf(" %s\n", carry_str); // Print carry without shifting
    printf("%*s\n", max_len, str_a);
    printf("+%*s\n", max_len-1, str_b);
    printf("%.*s\n", max_len+1, "------");
    printf(" %s\n", result + len_res + 1);
}

int main() {
    int a, b;
    printf("Podaj liczby a i b:\na = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    
    print_addition(a, b);
    
    return 0;
}
