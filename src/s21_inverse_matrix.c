#include "s21_matrix.h"


int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int status = OK;

    if (is_matrix_correct(A)) {
        status = INCORRECT_M;
    } else if (A->rows != A->columns) {
        status = CALC_ERROR;
    }

    if (status == OK) {
        // Поиск определителя
        double det;
        s21_determinant(A, &det);


//        if (fabs(det) < 1e-6) {
//            status = CALC_ERROR;
//        }

        if (det != 0) {
            s21_create_matrix(A->rows, A->columns, result);

            // Матрица алгебраических дополнений будет равна:
            matrix_t calc_comp;
            s21_calc_complements(A, &calc_comp);


            // Транспонированная матрица алгебраических дополнений
            s21_transpose(&calc_comp, result);

            // Разбираемся со знаками
            int sign = 1;
            for (int i = 0; i < result->rows; i++) {
                for (int j = 0; j < result->columns; j++) {
                    if (j % 2 == 0)
                        sign = -1;
                    else
                        sign = 1;
                    result->matrix[i][j] *= sign;
                }
            }
        } else {
            // Обратной матрицы не существует
        }

    }






    return status;
}