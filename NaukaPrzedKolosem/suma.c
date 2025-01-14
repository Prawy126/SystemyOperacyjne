#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR 10
int dane[ROZMIAR];

int main(){
	for(int i = 0; i<ROZMIAR; i++){
		dane[i]=i+1;
	}
	
	int minimum = dane[0];
	int maximum = dane[0];
	int suma = 0;

	for(int i = 0; i<ROZMIAR; i++){
		int wartosc = dane[i];
		suma+=wartosc;
		if(wartosc<minimum){
			minimum = wartosc;
		}
		if(wartosc>maximum){
			maximum = wartosc;
		}
	}

	printf("Suma jednowatokowa: %d\n", suma);
	printf("Minimum w tablicy %d\n", minimum);
	printf("Makximum w tablicy: %d\n", maximum);

	return 0;
}
