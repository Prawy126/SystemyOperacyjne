#include <stdio.h>

int wariacje1(){
	int znaki = ('z' - 'a' + 1)+ ('Z' - 'A' + 1) + ('9' - '0' + 1) + 1 + 1;
	return znaki * znaki;
}

int main(){

	printf("Wariacje1: %d\n", wariacje1());
	return 0;
}
