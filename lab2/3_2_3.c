#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *login(const char *name, const char *surname) {

    char *fullName = (char *)malloc(strlen(surname) + 2);

    fullName[0] = name[0];
    strcpy(&fullName[1], surname);

    return fullName;
}

int main() {

    char *fullName = login("Jan", "Nowak");

    printf("%s\n", fullName);
    free(fullName);

    return 0;
}
 