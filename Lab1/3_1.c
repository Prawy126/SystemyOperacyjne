#include <stdio.h>;
#include <stdlib.h>;
struct Fraction {
    int num, den;
};
/*
a/b + c/d = (a*d)/(b*d) + (c*b)/(d*b) = (a*d + c*b) / (b*d)
*/
struct Fraction sum(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    int c = y.num;
    int d = y.den;
    struct Fraction z;
    z.num = a*d + c*b;
    z.den = b*d;
    return z;
}



struct Fraction subs(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    int c = y.num;
    int d = y.den;
    struct Fraction z;
    z.num = a*d - c*b;
    z.den = b*d;
    return z;
}



struct Fraction mul(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    int c = y.num;
    int d = y.den;
    struct Fraction z;
    z.num = a*c;
    z.den = b*d;
    return z;
}



struct Fraction divv(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;
    int c = y.num;
    int d = y.den;
    struct Fraction z;
    z.num = a*d;
    z.den = b*c;
    return z;
}





void main() {
    struct Fraction x = {2, 3};
    struct Fraction y = {1, 4};



    struct Fraction z1 = sum(x, y);
    printf("%d/%d + %d/%d = %d/%d\n", x.num, x.den,y.num, y.den, z1.num, z1.den);



    struct Fraction z2 = subs(x, y);
    printf("%d/%d - %d/%d = %d/%d\n", x.num, x.den,y.num, y.den, z2.num, z2.den);



    struct Fraction z3 = mul(x, y);
    printf("%d/%d * %d/%d = %d/%d\n", x.num, x.den,y.num, y.den, z3.num, z3.den);



    struct Fraction z4 = divv(x, y);
    printf("%d/%d : %d/%d = %d/%d\n", x.num, x.den,y.num, y.den, z4.num, z4.den);
}