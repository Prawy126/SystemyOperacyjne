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
    int cyfra = -13654;
    printf("cyfry1(%d): %d\n", cyfra, cyfry1(cyfra));
    printf("cyfry2(%d): %d\n", cyfra, cyfry2(cyfra));
    printf("cyfry3(%d): %d\n", cyfra, cyfry3(cyfra));
    return 0;
}