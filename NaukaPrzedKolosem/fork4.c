#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	printf("Poczatek\n");

	pid_t pid = fork();

	if(pid == 0) printf("Proces dziecko, pid = %d\n", getpid());
	else if(pid >0){
		printf("Proces rodzic, pid = %d\n", getpid());
		wait(NULL);
	}
	
	printf("Koniec\n");

	return 0;
}

