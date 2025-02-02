#include <unistd.h>

int main() {
    char msg[] = "Hello, system call!\n";
    write(1, msg, sizeof(msg) - 1);  // Deskryptor 1 - standardowe wyjście
    _exit(0);
}
