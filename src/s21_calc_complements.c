#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    // Проверка на то, что матрицы квадратные

    s21_create_matrix(A->rows, A->columns, result);
    matrix_t minor_result;

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = count_minor(i, j, A);

//            get_minor(i, j, A, &minor_result);



//            print_matrix(&minor_result);


        }
    }
//            result->matrix[i][j] = matrix_minor(i, j, A);

    return 0;
}