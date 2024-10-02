#include <stdio.h>
#include <stdlib.h>

int indexOf(const char *str, char c){
    int i = 0;
    while(str[i] != c){
        if (str[i] == '\0'){
            return 0;
            }
            i++;
        }
    return i;
}


int main() {
    char str[5] = "99$ ";
    int a = indexOf(str,'$');
    printf("index = %d",a);

}