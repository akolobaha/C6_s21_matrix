#include "s21_matrix.h"

int main() {
    matrix_t matrix_a;
    s21_create_matrix(5, 4, &matrix_a);

    fill_matrix(&matrix_a);
    print_matrix(&matrix_a);

    matrix_t matrix_b;
    s21_create_matrix(5, 4, &matrix_b);


    fill_matrix(&matrix_b);
    matrix_b.matrix[0][1] = 2.0000;
    print_matrix(&matrix_b);

    printf("\neq_matr: %d", s21_eq_matrix(&matrix_a, &matrix_b));



    return 0;
}