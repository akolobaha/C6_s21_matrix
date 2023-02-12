#include "s21_matrix.h"


int s21_determinant(matrix_t *A, double *result) {
    int degree = 1;
    int status = OK;

    if (A->rows == 1) {
        *result = A->matrix[0][0];
        return status;
    } else if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
        return status;
    } else {
        double lasting_result = 0;
        for (int i = 0; i < A->columns; i++) {
            matrix_t crop_matrix;
            cut_matrix(0, i, A, &crop_matrix);


            s21_determinant(&crop_matrix, result);

            lasting_result += *result * A->matrix[0][i] * degree;
            degree *= -1;

        }
        *result = lasting_result;
    }

    return status;
}
