#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *login(const char *name, const char *surname)
{
  const size_t len1 = strlen(name);
   const size_t len2 = strlen(surname);
   char *result = malloc(33); // +1 for the null-terminator
   // in real code you would check for errors in malloc here
   memcpy(result, name, sizeof(char));
   memcpy(result + sizeof(char), surname, len2 + 1); // +1 to copy the null-terminator
   return result;

}

int main() {

    char *fullName = login("Jan", "Nowak");

    printf("%s\n", fullName);
    free(fullName);

    return 0;
}
 