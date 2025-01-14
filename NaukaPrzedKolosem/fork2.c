#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){

	printf("Poczatek\n");

	pid_t pid = fork();
	
	if(pid < 0) fprintf(stderr, "Blad tworzenia procesu potomnego\n");
	
	if(pid == 0) printf("Proces dziecko, zmienna pid = %d\n", pid);

	if(pid > 0) printf("Proces rodzic, zmiennna pid = %d\n", pid);

	printf("Koniec\n");

	return 0;
}
