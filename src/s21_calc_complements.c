#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    // Проверка на то, что матрицы квадратные

    double minor = matrix_minor(0, 0, A, result);

    return 0;
}