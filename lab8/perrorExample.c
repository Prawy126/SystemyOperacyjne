#include <stdio.h>
#include <stdlib.h>

void perrorExample() {
    FILE *file = fopen("nonexistentfile.txt", "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fclose(file);
}

int main() {
    perrorExample();
    return 0;
}
