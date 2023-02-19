#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int status = OK;

    if (!is_matrix_consistent(*A, *B))
        status = CALC_ERROR;

    if (!is_matrix_correct(A) || !is_matrix_correct(B))
        status = INCORRECT_M;

//    if (status == INCORRECT_M || status == CALC_ERROR)
//        res = FAILURE;


//    if (result == NULL)
//        res = CALC_ERROR;

    if (status == OK) {
        s21_create_matrix(A->rows, A->rows, result);
        fill_matrix_val(result, 0);

        for (int i = 0; i < A->rows && status == OK; i++)
            for (int j = 0; j < B->columns; j++)
                for (int k = 0; k < A->columns; k++)
                    result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    }

    return status;
}