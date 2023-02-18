#include "s21_matrix.h"

int main() {

    matrix_t A = {NULL, 0, 0};
    matrix_t B = {NULL, 0, 0};
    matrix_t result = {NULL, 0, 0};
    matrix_t result_full = {NULL, 0, 0};

    s21_create_matrix(2, 3, &A);
    s21_create_matrix(2, 3, &B);
    s21_create_matrix(2, 3, &result_full);

    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.columns; j++) {
            A.matrix[i][j] = j + 1 + 81230.0000001;
            B.matrix[i][j] = j + 1 + 2.0000001;
            result_full.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
        }
    }

    print_matrix(&A);
    print_matrix(&B);
    print_matrix(&result);

    int ass_0 = s21_sub_matrix(&A, &B, &result);

//    for (int i = 0; i < A.rows; i++) {
//        for (int j = 0; j < A.columns; j++) {
//            printf("%f == %f\n", result.matrix[i][j], result_full.matrix[i][j]);
//        }
//    }
//
//    s21_remove_matrix(&A);
//    s21_remove_matrix(&B);
//    s21_remove_matrix(&result);
//    s21_remove_matrix(&result_full);

    return 0;


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

    s21_inverse_matrix(&matrix_a, &matrix_res);

    printf("determinant %f", det_result);

//    printf("consistent: %d", is_matrix_consistent(matrix_a, matrix_b));

//    printf("\neq_matr: %d", s21_mult_matrix(&matrix_a, &matrix_b, &matrix_res));

//    print_matrix(&matrix_res);

//    s21_calc_complements(&matrix_a, &matrix_res);

    print_matrix(&matrix_res);



    return 0;
}