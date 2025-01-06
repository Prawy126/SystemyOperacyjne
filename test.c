#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

char *trim(char *s){
    
    int poczatek = 0;
    int koniec = strlen(s)-1;
    
    //wyliczamy gdzie faktycznie jest początek
    while(isspace(s[poczatek])){
        poczatek++;
    }
    //wyliczamy gdzie faktycznie jest koniec
    while (koniec>=poczatek && isspace(s[koniec]))
    {
        koniec--;
    }
    
    //obliczamy dłuogść nowego wyrazu/zdania
    int wyraz = koniec - poczatek + 1;
    
    //alokujemy miejsce na nowy wyraz
    char *zdanie = (char*)malloc(wyraz + 1);
    if(zdanie == NULL){
        return NULL;
    } 
    
    //tworzymy nowy wyraz
    strncpy(zdanie, s + poczatek,wyraz);
    zdanie[wyraz] = '\0';

    //zwracamy wyraz
    return zdanie;
    
}

int main(){
    //tworzymy wyraz
    char *wyraz = " tak moze ";
    
    //wywołujemy trim i wypisujemy wyraz bez pustych przestrzeni
    printf("%s",trim(wyraz));
    return 0;
}