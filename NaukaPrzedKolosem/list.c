#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char command[256]="";

	#ifdef _WIN32
		strcpy(command,"dir");
	#else
		strcpy(command,"ls");
	#endif

	for(int i = 1; i < argc; ++i){
		strcat(command, argv[i]);
		strcat(command," ");
	}

	system(command);
	return 0;
}
