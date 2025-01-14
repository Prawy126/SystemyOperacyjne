#include<stdio.h>
#include<errno.h>
#include<string.h>

void errnoExample(){
	FILE *file = fopen("nie_istnieje.txt", "r");
	if(file == NULL){
		printf("Error opening file: %s\n", strerror(errno));
	}
}

int main(){
	errnoExample();
	return 0;
} 
