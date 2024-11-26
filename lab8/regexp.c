#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

int main() {
    regex_t regex;
    int reti;
    char msgbuf[100];
    
    // Wyrażenie regularne POSIX do sprawdzenia formatu adresu e-mail
    char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    char *email = "test@example.com";
    
    // Kompilacja wyrażenia regularnego
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    // Dopasowanie wyrażenia regularnego
    reti = regexec(&regex, email, 0, NULL, 0);
    if (!reti) {
        puts("Email is valid");
    }
    else if (reti == REG_NOMATCH) {
        puts("Email is invalid");
    }
    else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    // Zwolnienie zasobów przydzielonych przez regcomp
    regfree(&regex);

    return 0;
}
