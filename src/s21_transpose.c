#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    int status = OK;
    int res = SUCCESS;

    if (is_matrix_size_positive(*A))
        status = INCORRECT_M;

    s21_create_matrix(A->columns, A->rows, result);
    if (result == NULL)
        status = CALC_ERROR;

    for (int i = 0; i < A->rows && status == OK; i++)
        for (int j = 0; j < A->columns; j++)
            result->matrix[j][i] = A->matrix[i][j];

    return status;
}