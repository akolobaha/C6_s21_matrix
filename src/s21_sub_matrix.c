#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int status = OK;

    if (!is_matrix_size_equal(A, B) || !is_matrix_size_equal(A, result))
        status = CALC_ERROR;
//
//    if (A->matrix == NULL || B->matrix == NULL)
//        status = CALC_ERROR;


//    if (is_matrix_size_positive(*A))
//        status = INCORRECT_M;
//
//    if (status == INCORRECT_M || status == CALC_ERROR)
//        res = FAILURE;


    for (int i = 0; i < A->columns && status == OK; i++) {
        for (int j = 0; j < A->rows; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
    }

    return status;
}