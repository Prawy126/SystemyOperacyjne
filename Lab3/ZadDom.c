 #include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>  // Potrzebne do isspace()

struct Fraction {
    int num, den;
};

struct Fraction sum(struct Fraction x, struct Fraction y) {
    struct Fraction z;
    z.num = x.num * y.den + y.num * x.den;
    z.den = x.den * y.den;
    return z;
}

struct Fraction sub(struct Fraction x, struct Fraction y) {
    struct Fraction z;
    z.num = x.num * y.den - y.num * x.den;
    z.den = x.den * y.den;
    return z;
}

struct Fraction mul(struct Fraction x, struct Fraction y) {
    struct Fraction z;
    z.num = x.num * y.num;
    z.den = x.den * y.den;
    return z;
}

struct Fraction quo(struct Fraction x, struct Fraction y) {
    struct Fraction z;
    z.num = x.num * y.den;
    z.den = x.den * y.num;
    return z;
}

void print(struct Fraction x, struct Fraction y, char op) {
    struct Fraction result;
    bool validOp = true;

    switch(op) {
        case '+': result = sum(x, y); break;
        case '-': result = sub(x, y); break;
        case '*': result = mul(x, y); break;
        case '/': result = quo(x, y); break;
        default: validOp = false; break;
    }

    if (validOp) {
        printf("%d/%d %c %d/%d = %d/%d\n", x.num, x.den, op, y.num, y.den, result.num, result.den);
    } else {
        printf("nieznaleziono działania\n");
    }
}

void printFraction(struct Fraction x) {
    if (x.den == 0) {
        printf("NaN");
    } else if (x.num == 0) {
        printf("0");
    } else if (x.num >= x.den) {
        int liczba = x.num / x.den;
        int reszta = x.num % x.den;
        if (reszta != 0) {
            printf("%d %d/%d", liczba, reszta, x.den);
        } else {
            printf("%d", liczba);
        }
    } else {
        printf("%d/%d", x.num, x.den);
    }
}

bool isNumber(const char *z) {
    while (*z) {
        if ((*z < '0' || *z > '9') && *z != '-') {
            return false;
        }
        z++;
    }
    return true;
}

int getFraction(struct Fraction *x, const char *s) {
    char *slash = strchr(s, '/');

    if (slash != NULL) {
        char numerator[slash - s + 1];
        char denominator[strlen(slash + 1) + 1];

        strncpy(numerator, s, slash - s);
        numerator[slash - s] = '\0';
        strcpy(denominator, slash + 1);

        if (isNumber(numerator) && isNumber(denominator)) {
            x->num = atoi(numerator);
            x->den = atoi(denominator);
            if (x->den == 0) {
                return 0;
            }
            return 1;
        }
    } else {
        if (isNumber(s)) {
            x->num = atoi(s);
            x->den = 1;
            return 1;
        }
    }
    return 0;
}

void trim(char *s) {
    int start = 0, end = strlen(s) - 1;

    while (isspace(s[start])) {
        start++;
    }

    while (end >= start && isspace(s[end])) {
        end--;
    }

    int length = end - start + 1;
    memmove(s, s + start, length);
    s[length] = '\0';  
}

void safeInput(char *buffer, int size) {
    fgets(buffer, size, stdin);
    if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    } else {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    trim(buffer);  
}

char getOperator() {
    char znak[10];
    bool valid = false;
    
    while (!valid) {
        printf("Podaj znak działania (+, -, *, /): ");
        safeInput(znak, sizeof(znak));  
        if (strlen(znak) == 1 && (znak[0] == '+' || znak[0] == '-' || znak[0] == '*' || znak[0] == '/')) {
            valid = true;
        } else {
            printf("Niepoprawny znak. Spróbuj ponownie.\n");
        }
    }
    return znak[0];
}

void getValidFraction(struct Fraction *f, const char *prompt) {
    char input[100];
    bool valid = false;
    
    while (!valid) {
        printf("%s", prompt);
        safeInput(input, sizeof(input));  
        if (getFraction(f, input)) {
            valid = true;
        } else {
            printf("Niepoprawny ułamek. Spróbuj ponownie.\n");
        }
    }
}

int main() {
    struct Fraction a, b;
    char znak;

    getValidFraction(&a, "Podaj a (np. 1/2 lub 3): ");
    znak = getOperator();
    getValidFraction(&b, "Podaj b (np. 1/2 lub 3): ");

    print(a, b, znak);

    return 0;
}
