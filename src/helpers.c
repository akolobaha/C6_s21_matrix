#include "s21_matrix.h"

void fill_matrix(matrix_t *matrix) {
    int count = 0;
    double **m_ptr = matrix->matrix;

    for (int i = 0; i < matrix->columns; i++) {
        for (int j = 0; j < matrix->rows; j++) {
            m_ptr[i][j] = ++count;
        }
    }
}

void print_matrix(matrix_t *matrix) {
    int count = 0;
    double **m_ptr = matrix->matrix;
    m_ptr[1][1];
    for (int i = 0; i < matrix->columns; i++) {
        printf("\n");
        for (int j = 0; j < matrix->rows; j++) {
            printf("%2.0f ", m_ptr[i][j]);
        }
    }
}

int is_matrix_size_negative(matrix_t matrix) {
    int status = 0;
    if (matrix.rows < 0 || matrix.columns < 0)
        status = 1;
    return status;
}



