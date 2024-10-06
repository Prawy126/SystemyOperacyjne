#include <stdlib.h>
#include <stdio.h>

float a1(int n){
   if(n == 0) return 1;
   if(n == 1) return 4;

   int k = n / 2;
   float a_k = a1(k);
   float a_k_minus_1 = a1(k - 1);
   return 2*a_k + 0.5 * a_k_minus_1; 
}

int main(){
    int n = 2;
    printf("a1(%d) = %f", n, a1(n));
    return 0;
}