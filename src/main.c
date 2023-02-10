#include "s21_matrix.h"

int main() {
    matrix_t matrix_a;
    s21_create_matrix(3, 2, &matrix_a);

//    fill_matrix(&matrix_a, 4);
    matrix_a.matrix[0][0] = 1;
    matrix_a.matrix[1][0] = 2;
    matrix_a.matrix[2][0] = 3;

    matrix_a.matrix[0][1] = 4;
    matrix_a.matrix[1][1] = 5;
    matrix_a.matrix[2][1] = 6;

    print_matrix(&matrix_a);

    matrix_t matrix_b;
    s21_create_matrix(2, 3, &matrix_b);


//    fill_matrix(&matrix_b, 1);


    matrix_b.matrix[0][0] = 1;
    matrix_b.matrix[1][0] = 2;

    matrix_b.matrix[0][1] = -1;
    matrix_b.matrix[1][1] = 3;

    matrix_b.matrix[0][2] = 1;
    matrix_b.matrix[1][2] = 4;

    print_matrix(&matrix_b);

    matrix_t matrix_res;

    printf("consistent: %d", is_matrix_consistent(matrix_a, matrix_b));

    printf("\neq_matr: %d", s21_mult_matrix(&matrix_a, &matrix_b, &matrix_res));

//    print_matrix(&matrix_res);



    return 0;
}