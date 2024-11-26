#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compareFiles(const char *file1, const char *file2) {
    FILE *fp1, *fp2;
    int ch1, ch2;
    int pos = 1, line = 1;
    int extraChars = 0;
    char extraFile[256];

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if (fp1 == NULL) {
        perror("Error opening first file");
        exit(EXIT_FAILURE);
    }

    if (fp2 == NULL) {
        perror("Error opening second file");
        fclose(fp1);
        exit(EXIT_FAILURE);
    }

    while (((ch1 = fgetc(fp1)) != EOF) && ((ch2 = fgetc(fp2)) != EOF)) {
        if (ch1 != ch2) {
            printf("Pliki różnią się od znaku nr %d w linii %d\n", pos, line);
            fclose(fp1);
            fclose(fp2);
            return;
        }
        if (ch1 == '\n') {
            line++;
            pos = 0;
        }
        pos++;
    }

    if (ch1 != EOF) {
        extraFile[0] = '\0';
        strcat(extraFile, file1);
        extraChars = 1;
        while ((ch1 = fgetc(fp1)) != EOF) {
            extraChars++;
        }
    }

    if (ch2 != EOF) {
        extraFile[0] = '\0';
        strcat(extraFile, file2);
        extraChars = 1;
        while ((ch2 = fgetc(fp2)) != EOF) {
            extraChars++;
        }
    }

    if (extraChars > 0) {
        printf("Plik %s zawiera %d znaków więcej niż zawartość pliku %s\n", extraFile, extraChars, (extraFile == file1) ? file2 : file1);
    } else {
        printf("Pliki są identyczne\n");
    }

    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    compareFiles(argv[1], argv[2]);

    return 0;
}
