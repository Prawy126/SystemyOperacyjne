#include <stdlib.h>
#include <stdio.h>

float a(int n){
    if(n == 0) return 1;
    if(n == 1) return 4;
    return 2*a(n-1)+0.5*a(n-2);
}

int main(){
    int n = 2;
    printf("a(%d) = %f", n, a(n));
    return 0;
}