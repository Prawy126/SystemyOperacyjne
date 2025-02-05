#include <signal.h>
#include <stdio.h>

void handler(int signum) {
    printf("Odebrano sygnał: %d\n", signum);
}

int main() {
    signal(SIGINT, handler);
    while (1);
}
