#include <stdlib.h>
#include <stdio.h>

int tab[] = {1,5,9};

void zmien(int *tab){
    tab++;
    *tab = 100;
    
}

int main(){
    zmien(tab);
    for(int i = 0; i<3; i++){
        printf("%d\n",tab[i]);
    }
    return 0;
}