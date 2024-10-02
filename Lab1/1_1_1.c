#include <stdio.h>
#include <stdlib.h>


int main() {

    int a;
    printf("a = ");
    scanf("%d", &a);
    printf("int value a = %d\n\n", a);

    float b;
    printf("b = ");
    scanf("%f", &b);
    printf("float value b = %f\n\n", b);

    char str[10];
    printf("c = ");
    scanf("%9s", str);
    printf("string value c = %s\n\n", str);

    fflush(stdin);
    printf("d = ");
    fgets(str, 10, stdin);
    printf("string value d = %s\n\n", str);

}