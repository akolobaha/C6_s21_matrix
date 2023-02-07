#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int status = OK;

    if (is_matrix_size_negative(*A) || is_matrix_size_negative(*B))

    if (A->columns != B->columns || A->rows != B->rows) {
        status = CALC_ERROR;
    }
}