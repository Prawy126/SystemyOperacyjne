#include <stdio.h>
#include <stdlib.h>
#include <gnu/libc-version.h>

void version_ldd(){
    system("ldd --version");
}
void version_gnu(){ 
    printf("GNU libc version: %s\n", gnu_get_libc_version()); 
}

void version_getconf(){
    system("getconf GNU_LIBC_VERSION"); 
}
int main(){
    version_ldd();
    version_getconf();
    version_gnu();
    return 0;
}
