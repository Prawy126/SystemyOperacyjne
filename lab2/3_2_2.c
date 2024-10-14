#include <stdlib.h>
#include <stdio.h>

char *identity(const char *name, const char *surname) {
    char *str = (char*)malloc((strlen(name) + 2 + strlen(surname)));
    strcpy(str, name);
    strcat(str, " ");
    strcat(str, surname);
    return str;
}

int main()
{
    char *full_name = identity("Jan", "Kowalski");
    printf("%s\n", full_name);
    return 0;
}
 