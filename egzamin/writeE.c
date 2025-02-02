#include <unistd.h>

int main() {
    char error_msg[] = "This is an error message!\n";
    write(2, error_msg, sizeof(error_msg) - 1);  // Deskryptor 2 - standardowe wyjście błędów
    _exit(0);
}
