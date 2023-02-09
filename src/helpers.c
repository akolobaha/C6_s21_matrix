#include "s21_matrix.h"

void fill_matrix(matrix_t *matrix, int mul) {
    int count = 0;
    double **m_ptr = matrix->matrix;

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            m_ptr[i][j] = ++count;
        }
    }
}

void print_matrix(matrix_t *matrix) {
    int count = 0;
    double **m_ptr = matrix->matrix;
    m_ptr[1][1];
    for (int i = 0; i < matrix->rows; i++) {
        printf("\n");
        for (int j = 0; j < matrix->columns; j++) {
            printf("%12.7f ", m_ptr[i][j]);
        }
    }
    printf("\n");
}

int is_matrix_size_positive(matrix_t matrix) {
    int status = 0;
    if (matrix.rows < 0 || matrix.columns < 0)
        status = 1;
    return status;
}

int is_matrix_size_equal(matrix_t *A, matrix_t *B) {
    int status = 0;
    if (A->rows == B->rows && A->columns == B->columns)
        status = 1;

    return status;
}

// Консистентны, ширина равна длинне и наоборот
int is_matrix_consistent(matrix_t A, matrix_t B) {
    int status = 0;
    if (A.rows == B.columns && A.columns == B.rows)
        status = 1;

    return status;
}

int compare_doubles(double a, double b) {
    return fabs(a - b) < TOL;
}