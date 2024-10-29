#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Fraction {
    int numerator;
    int denominator;
};

int isNumber(const char *s) {
    if (*s == '-' || *s == '+') s++;
    if (*s == '\0') return 0;
    while (*s != '\0') {
        if (!isdigit(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

int getFraction(struct Fraction *x, const char *s) {
    
    const char *slash = strchr(s, '/');
    
    if (slash == NULL) {
        
        if (isNumber(s)) {
            x->numerator = atoi(s);  
            x->denominator = 1;      
            return 1;
        }
    } else {
        
        char numerator_part[100];
        char denominator_part[100];

        strncpy(numerator_part, s, slash - s);
        numerator_part[slash - s] = '\0';  

        strcpy(denominator_part, slash + 1);
        
        if (isNumber(numerator_part) && isNumber(denominator_part)) {
            x->numerator = atoi(numerator_part);
            x->denominator = atoi(denominator_part);
            
            if (x->denominator == 0) {
                return 0;  
            }
            return 1;
        }
    }
    return 0;  
}

int main() {
    const char *tests[] = {"37", "37/5", "123/0", "abc", "-7/8", "9/", "/4", "3/7"};
    int n = sizeof(tests) / sizeof(tests[0]);
    struct Fraction frac;

    for (int i = 0; i < n; i++) {
        if (getFraction(&frac, tests[i])) {
            printf("Test %d: %s -> Licznik: %d, Mianownik: %d\n", i + 1, tests[i], frac.numerator, frac.denominator);
        } else {
            printf("Test %d: %s -> Niepoprawny ulamek lub liczba\n", i + 1, tests[i]);
        }
    }

    return 0;
}
