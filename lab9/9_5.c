#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyLast10Chars(FILE *source, FILE *dest) {
    fseek(source, -10, SEEK_END);
    char ch;
    while (fread(&ch, sizeof(char), 1, source)) {
        fwrite(&ch, sizeof(char), 1, dest);
    }
}

void copyLast10Words(FILE *source, FILE *dest) {
    fseek(source, 0, SEEK_SET);
    char ch;
    long wordPositions[10] = {0};
    int wordCount = 0;
    long pos = 0;
    
    while ((ch = fgetc(source)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            wordPositions[wordCount % 10] = pos;
            wordCount++;
        }
        pos = ftell(source);
    }
    
    int start = (wordCount > 10) ? (wordCount % 10) : 0;
    int end = start + ((wordCount > 10) ? 10 : wordCount);
    
    fseek(source, wordPositions[start], SEEK_SET);
    while ((ch = fgetc(source)) != EOF) {
        fwrite(&ch, sizeof(char), 1, dest);
    }
}

void copyLast10Lines(FILE *source, FILE *dest) {
    fseek(source, 0, SEEK_SET);
    char ch;
    long linePositions[10] = {0};
    int lineCount = 0;
    long pos = 0;
    
    while ((ch = fgetc(source)) != EOF) {
        if (ch == '\n') {
            linePositions[lineCount % 10] = pos;
            lineCount++;
        }
        pos = ftell(source);
    }
    
    int start = (lineCount > 10) ? (lineCount % 10) : 0;
    int end = start + ((lineCount > 10) ? 10 : lineCount);
    
    fseek(source, linePositions[start], SEEK_SET);
    while ((ch = fgetc(source)) != EOF) {
        fwrite(&ch, sizeof(char), 1, dest);
    }
}

void copyLastParts(const char *sourceFile, const char *destFile) {
    FILE *source = fopen(sourceFile, "r");
    if (!source) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE *dest = fopen(destFile, "w");
    if (!dest) {
        perror("Error opening destination file");
        fclose(source);
        exit(EXIT_FAILURE);
    }

    fprintf(dest, "Last 10 characters:\n");
    copyLast10Chars(source, dest);
    fprintf(dest, "\n\nLast 10 words:\n");
    copyLast10Words(source, dest);
    fprintf(dest, "\n\nLast 10 lines:\n");
    copyLast10Lines(source, dest);

    fclose(source);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }

    copyLastParts(argv[1], argv[2]);

    printf("Finished copying last parts.\n");
    return 0;
}
