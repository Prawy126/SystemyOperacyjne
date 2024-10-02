#include <stdio.h>
#include <stdlib.h>

struct Fraction {
    int num, den;
};

struct Fraction sum(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a * d + c * b;
    z.den = b * d;

    return z;
}

struct Fraction sub(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a * d - c * b;
    z.den = b * d;

    return z;
}

struct Fraction mul(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a * c;
    z.den = b * d;

    return z;
}

struct Fraction quo(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a * d;
    z.den = b * c;

    return z;
}

void print(struct Fraction x, struct Fraction y, const char operator) {
    struct Fraction result;

    switch (operator) {
        case '+':
            result = sum(x, y);
            printf("%d/%d + %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, result.num, result.den);
            break;
        case '-':
            result = sub(x, y);
            printf("%d/%d - %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, result.num, result.den);
            break;
        case '*':
            result = mul(x, y);
            printf("%d/%d * %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, result.num, result.den);
            break;
        case '/':
            result = quo(x, y);
            printf("%d/%d / %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, result.num, result.den);
            break;
        case ':':
            result = quo(x, y);
            printf("%d/%d : %d/%d = %d/%d\n", x.num, x.den, y.num, y.den, result.num, result.den);
            break;
        default:
            printf("$ - nieznane dzialanie\n");
            break;
    }
}

int main() {
    struct Fraction x = {2, 3};
    struct Fraction y = {1, 4};

    print(x, y, '+');
    print(x, y, '-');
    print(x, y, '*');
    print(x, y, '/');
    print(x, y, ':');
    print(x, y, '$');  

    return 0;
}

 