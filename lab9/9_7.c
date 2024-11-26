#include <stdio.h>
#include <stdlib.h>

void combineFiles(int fileCount, char *fileNames[], const char *outputFile) {
    FILE *destFile = fopen(outputFile, "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < fileCount; i++) {
        FILE *sourceFile = fopen(fileNames[i], "r");
        if (sourceFile == NULL) {
            perror("Error opening source file");
            fclose(destFile);
            exit(EXIT_FAILURE);
        }

        char ch;
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(ch, destFile);
        }

        fclose(sourceFile);
    }

    fclose(destFile);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source_file1> <source_file2> ... <destination_file>\n", argv[0]);
        return 1;
    }

    int fileCount = argc - 2;
    char **fileNames = &argv[1];
    const char *outputFile = argv[argc - 1];

    combineFiles(fileCount, fileNames, outputFile);

    printf("Files combined successfully into %s.\n", outputFile);
    return 0;
}
