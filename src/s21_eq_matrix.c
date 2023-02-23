#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int result = SUCCESS;


    if ((s21_is_empty(A) == 0 && s21_is_empty(B) == 0 &&
         A->columns == B->columns && A->rows == B->rows)) {
        for (int i = 0; i < A->rows && result == SUCCESS; i++) {
            for (int j = 0; j < A->columns; j++)
                if (!compare_doubles(A->matrix[i][j], B->matrix[i][j]))
                    result = FAILURE;
        }
    } else {
        result = FAILURE;
    }

    return result;
}