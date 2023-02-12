#include "s21_matrix.h"


int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    // Поиск определителя
    double det;
    s21_determinant(A, &det);

    if (det != 0) {
        // Матрица алгебраических дополнений будет равна:
        matrix_t calc_comp;
        s21_calc_complements(A, &calc_comp);

        print_matrix(&calc_comp);

        // Транспонированная матрица алгебраических дополнений
        s21_transpose(&calc_comp, result);

    } else {
        // Обратной матрицы не существует
    }
}