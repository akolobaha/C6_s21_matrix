#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    // Проверка на то, что матрицы квадратные
    int status = OK;

    if (is_matrix_size_positive(*A)) {
        status = INCORRECT_M;
    } else if (!is_matrix_correct(A))
        status = INCORRECT_M;
    else if (A->rows != A->columns)
        status = CALC_ERROR;



    if (status == OK) {
        s21_create_matrix(A->rows, A->columns, result);
        matrix_t minor_result;
        double double_res;
        int sign = 1;

        if (A->rows == 1) {
            result->matrix[0][0] = A->matrix[0][0];
        } else {
            for (int i = 0; i < A->rows; i++) {
                sign *= -1;
                for (int j = 0; j < A->columns; j++) {
                    matrix_t cut_m;
                    cut_matrix(i, j, A, &cut_m);

                    double_res = 0;

                    s21_determinant(&cut_m, &double_res);

                    sign *= -1;
                    result->matrix[i][j] = double_res * sign;
                }
            }
        }


    }

    return status;
}