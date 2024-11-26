#include <stdio.h>

int wariacje2() {
    // Znakowe wartości, które pasują do wyrażenia regularnego [a-zA-Z0-9./]
    char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
    int length = sizeof(chars) - 1; // odejmujemy 1, ponieważ sizeof uwzględnia '\0'

    int count = 0;

    // Przechodzimy przez wszystkie możliwe kombinacje 2-elementowe
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            //printf("%c%c\n", chars[i], chars[j]);
            count++;
        }
    }

    return count;
}

int main() {
    int wynik = wariacje2();
    printf("Liczba możliwych 2-elementowych ciągów: %d\n", wynik);
    return 0;
}
