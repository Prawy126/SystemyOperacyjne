#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void trimNewline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) *pos = '\0';
    if ((pos = strchr(str, '\r')) != NULL) *pos = '\0';
}

void addUser(const char *username, const char *fullname, const char *password) {
    char command[MAX_LINE_LENGTH];

    snprintf(command, sizeof(command), "sudo useradd -m -c \"%s\" -p $(openssl passwd -1 %s) %s",
             fullname, password, username);
    
    int result = system(command);
    if (result == -1) {
        perror("Błąd wykonania komendy");
    } else if (result != 0) {
        fprintf(stderr, "Nie udało się dodać użytkownika: %s\n", username);
    } else {
        printf("Użytkownik %s został pomyślnie dodany.\n", username);
    }
}

int main() {
    FILE *file = fopen("baza.txt", "r");
    if (file == NULL) {
        perror("Nie można otworzyć pliku baza.txt");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        trimNewline(line);

        char *username = strtok(line, ";");
        char *fullname = strtok(NULL, ";");
        char *password = strtok(NULL, ";");

        if (username && fullname && password) {
            addUser(username, fullname, password);
        } else {
            fprintf(stderr, "Niepoprawny format linii: %s\n", line);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
