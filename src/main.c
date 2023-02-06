#include "s21_matrix.h"

int main() {
    matrix_t matrix;
    s21_create_matrix(5, 5, &matrix);

    fill_matrix(&matrix);
    print_matrix(&matrix);
    printf("%f ", matrix.matrix[1][1]);

    s21_remove_matrix(&matrix);

    printf("%f ", matrix.matrix[1][1]);



    return 0;
}