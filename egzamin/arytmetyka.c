#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;

    printf("Pierwszy element: %d\n", *ptr);
    ptr++;
    printf("Drugi element: %d\n", *ptr);

    return 0;
}
