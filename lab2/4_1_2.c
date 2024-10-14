#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
char *trim(char *s) {
    while (isspace(*s)) s++;
    char *end = s + strlen(s) - 1;
    while (end > s && isspace(*end)){
		end--;
	}
    *(end + 1) = '\0';
    return s;
}
 
int main() {
    char str[] = "   ala   ";
    printf("'%s'\n", trim(str));
    return 0;
}