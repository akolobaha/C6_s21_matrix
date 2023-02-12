#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    // Проверка на то, что матрицы квадратные

    s21_create_matrix(A->rows, A->columns, result);
    matrix_t minor_result;
    double double_res;
    int sign = -1;

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            matrix_t cut_m;
            cut_matrix(i, j, A, &cut_m);

            double_res = 0;

            s21_determinant(&cut_m, &double_res);

            sign *= -1;
            result->matrix[i][j] = double_res * sign;
        }

    }

    return 0;
}