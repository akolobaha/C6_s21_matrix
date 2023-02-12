#include "s21_matrix.h"

int main() {
    matrix_t matrix_a;
    s21_create_matrix(3, 3, &matrix_a);

//    fill_matrix(&matrix_a, 4);
    matrix_a.matrix[0][0] = 2;
    matrix_a.matrix[1][0] = 6;
    matrix_a.matrix[2][0] = 5;
//    matrix_a.matrix[3][0] = 5;

    matrix_a.matrix[0][1] = 5;
    matrix_a.matrix[1][1] = 3;
    matrix_a.matrix[2][1] = -2;
//    matrix_a.matrix[3][1] = 2;

    matrix_a.matrix[0][2] = 7;
    matrix_a.matrix[1][2] = 4;
    matrix_a.matrix[2][2] = -3;
//    matrix_a.matrix[3][2] = 1;

//    matrix_a.matrix[0][3] = 3;
//    matrix_a.matrix[1][3] = 2;
//    matrix_a.matrix[2][3] = 1;
//    matrix_a.matrix[3][3] = 1;

//    fill_matrix(&matrix_a, 1);

    print_matrix(&matrix_a);


//    matrix_t matrix_b;
//    s21_create_matrix(2, 3, &matrix_a);


//    fill_matrix(&matrix_b, 1);


//    matrix_b.matrix[0][0] = 1;
//    matrix_b.matrix[1][0] = 2;
//
//    matrix_b.matrix[0][1] = -1;
//    matrix_b.matrix[1][1] = 3;
//
//    matrix_b.matrix[0][2] = 1;
//    matrix_b.matrix[1][2] = 4;
//
//    print_matrix(&matrix_b);

    matrix_t matrix_res;

    double det_result;
    det_result = 0;

    s21_calc_complements(&matrix_a, &matrix_res);

    printf("determinant %f", det_result);

//    printf("consistent: %d", is_matrix_consistent(matrix_a, matrix_b));

//    printf("\neq_matr: %d", s21_mult_matrix(&matrix_a, &matrix_b, &matrix_res));

//    print_matrix(&matrix_res);

//    s21_calc_complements(&matrix_a, &matrix_res);

    print_matrix(&matrix_res);



    return 0;
}