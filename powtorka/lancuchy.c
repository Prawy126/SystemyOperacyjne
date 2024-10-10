#include <stdlib.h>
#include <stdio.h>

void zmien(char *tekst){
    char *koniec, temp;  
    
    while(*tekst != ' ' && *tekst!=0){
        tekst++;
        
    }
    tekst++;
    
    koniec = tekst;
    while(*koniec != ' ' && *koniec!= 0){
        koniec++;
    }
    koniec--;
    int dlugosc = ((koniec - tekst) + 1)/2;

    for(dlugosc;dlugosc>0;dlugosc--){
        temp = *tekst;
        *tekst = *koniec;
        *koniec = temp;
        tekst++;
        koniec--;
    }

}

char tekst[] = "Kurs programowania C";

int main(){
    zmien(tekst);
    printf("%s\n", tekst);
    return 0;
}