#include<stdio.h>
#include <ctype.h>
 
int isNumber(const char *s)
{
    if(s == NULL || *s == '\0')
    {
        printf("AMIGO BEZ TAKICH!\n");
        return 0;
    }
 
    while(*s)
    {
        if(*s == '-')
        {
            s++;
        }
 
        if(!isdigit(*s))
        {
            return 0;
        }
        s++;
    }
 
    return 1;
}
 
 
int main()
{
    const char *tekst = "";
    printf("Test tekstu: %s -> %d", tekst, isNumber(tekst));
    return 0;
}