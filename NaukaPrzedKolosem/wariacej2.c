#include <stdio.h>

int wariacje2() {
	char znaki[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
	int count = 0;
	for(int i = 0; znaki[i] != '\0'; i++){
		for(int j = 0; znaki[j] != '\0'; j++){
			count++;
		}
	}
	return count;
}

int main(){
	printf("Wariacje2: %d\n", wariacje2());
	return 0;
}
