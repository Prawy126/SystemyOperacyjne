#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void trimNewline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) *pos = '\0';
    if ((pos = strchr(str, '\r')) != NULL) *pos = '\0';
}

void deleteUser(const char *username) {
    char command[MAX_LINE_LENGTH];
    snprintf(command, sizeof(command), "sudo userdel -r \"%s\"", username);
    int result = system(command);
    if (result == -1) {
        perror("Błąd wykonania komendy");
    } else if (result != 0) {
        fprintf(stderr, "Nie udało się usunąć użytkownika: %s\n", username);
    } else {
        printf("Użytkownik %s został pomyślnie usunięty.\n", username);
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
        if (username) {
            deleteUser(username);
        } else {
            fprintf(stderr, "Niepoprawny format linii: %s\n", line);
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
}
