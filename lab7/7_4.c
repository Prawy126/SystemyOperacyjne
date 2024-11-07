#include <stdlib.h> 
#include <stdio.h> 
#include <math.h>

int cyfry1(int cyfry){
    if(cyfry == 0) return 1;
    cyfry = abs(cyfry);
    return (int)log10((double)cyfry)+1;
}

int cyfry2(int cyfry){
    if(cyfry == 0) return 1;
    cyfry = abs(cyfry);
    char buffer[50];
    int n = snprintf(buffer, sizeof(buffer), "%d", cyfry);

    return (int)n;
}

int cyfry3(int cyfry){
    if(cyfry == 0) return 1;
    int licz = 0;
    while(cyfry !=0){
        cyfry = cyfry/10;
        licz++;
    }
    return licz;
    
}

int main(){
    printf("%d\n",cyfry2(-13232132));
    return 0;
}