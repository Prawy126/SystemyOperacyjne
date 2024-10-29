#include <stdio.h>
#include <string.h>

int getOperator(char *op, const char *s) {
    // Sprawdzenie czy napis jest operatorem arytmetycznym
    if (strlen(s) == 1 && (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == ':')) {
        *op = *s; // Zapisz operator do zmiennej 'op'
        return 1; // Poprawny operator
    }
    return 0; // Niepoprawny operator
}

int main() {
    const char *tests[] = {"+", "-", "abc", "*", ":", "/", "xyz"};
    int n = sizeof(tests) / sizeof(tests[0]);
    char op;

    for (int i = 0; i < n; i++) {
        if (getOperator(&op, tests[i])) {
            printf("Test %d: %s -> Operator: %c\n", i + 1, tests[i], op);
        } else {
            printf("Test %d: %s -> Niepoprawny operator\n", i + 1, tests[i]);
        }
    }

    return 0;
}
