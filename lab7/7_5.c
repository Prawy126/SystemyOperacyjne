#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
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

#elif _WIN32
    #include <windows.h>

    void version_ldd() {
        printf("Windows does not use ldd. Equivalent functionality is not available.\n");
    }

    void version_gnu() {
        printf("GNU libc is not used on Windows.\n");
    }

    void version_getconf() {
        printf("Windows version information:\n");
        system("ver"); 

       
        printf("GCC compiler version:\n");
        system("gcc --version");
    }

#endif

int main() {
    version_ldd();
    version_getconf();
    version_gnu();
    return 0;
}
