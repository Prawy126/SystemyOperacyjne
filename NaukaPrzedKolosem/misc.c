#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int losuj(int a, int b){

	return a + rand() % (b - a);
}

int main(){
	srand(time(NULL));
	printf("Losowa liczba: %d\n",losuj(1,10));
	return 0;
}
