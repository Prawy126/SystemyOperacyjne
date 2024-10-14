#include <stdio.h>
#include <stdlib.h>

// Definicja struktury zawierającej wskaźnik do wskaźnika
typedef struct {
    int ***data;
    int layers;
    int rows;
    int cols;
} ComplexStructure;

// Funkcja zwracająca wskaźnik do wskaźnika do wskaźnika (alokacja 3D)
int ***allocate_3D_array(int layers, int rows, int cols) {
    int ***array = (int ***)malloc(layers * sizeof(int **));
    for (int i = 0; i < layers; i++) {
        array[i] = (int **)malloc(rows * sizeof(int *));
        for (int j = 0; j < rows; j++) {
            array[i][j] = (int *)malloc(cols * sizeof(int));
        }
    }
    return array;
}

// Funkcja, która zwraca wskaźnik do funkcji zwracającej wskaźnik do wskaźnika
int ***(*get_allocator())(int, int, int) {
    return &allocate_3D_array;
}

// Funkcja wypełniająca 3-wymiarową tablicę wartościami
void fill_3D_array(int ***array, int layers, int rows, int cols) {
    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                array[i][j][k] = i + j + k;
            }
        }
    }
}

// Funkcja wypisująca 3-wymiarową tablicę
void print_3D_array(int ***array, int layers, int rows, int cols) {
    for (int i = 0; i < layers; i++) {
        printf("Layer %d:\n", i);
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                printf("%d ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Funkcja zwalniająca pamięć 3-wymiarowej tablicy
void free_3D_array(int ***array, int layers, int rows) {
    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < rows; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}

int main() {
    // Tworzenie wskaźnika do struktury
    ComplexStructure *cs = (ComplexStructure *)malloc(sizeof(ComplexStructure));

    // Parametry
    int layers = 2;
    int rows = 3;
    int cols = 3;

    // Ustawienia parametrów w strukturze
    cs->layers = layers;
    cs->rows = rows;
    cs->cols = cols;

    // Uzyskanie wskaźnika do funkcji zwracającej wskaźnik do wskaźnika do wskaźnika
    int ***(*allocator)(int, int, int) = get_allocator();

    // Alokacja pamięci dla struktury
    cs->data = allocator(layers, rows, cols);

    // Wypełnianie wartościami i wypisywanie
    fill_3D_array(cs->data, layers, rows, cols);
    print_3D_array(cs->data, layers, rows, cols);

    // Zwalnianie pamięci
    free_3D_array(cs->data, layers, rows);
    free(cs);

    return 0;
}
