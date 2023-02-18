#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int result = SUCCESS;

//    if (is_matrix_size_positive(*A) || is_matrix_size_positive(*B))
//        status = INCORRECT_M;
//
    if (!is_matrix_size_equal(A, B))
        result = FAILURE;
//
//    if (status == INCORRECT_M || status == CALC_ERROR)
//        result = FAILURE;


    if (A->matrix == NULL && B->matrix == NULL)
        result = FAILURE;

    for (int i = 0; i < A->columns && result == SUCCESS; i++) {
        for (int j = 0; j < A->rows; j++) {
            if (!compare_doubles(A->matrix[i][j], B->matrix[i][j]))
                result = FAILURE;
        }
    }

    return result;
}