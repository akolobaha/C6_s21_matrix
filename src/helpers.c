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

void fill_matrix_val(matrix_t *matrix, int val) {
    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->columns; j++)
            matrix->matrix[i][j] = val;
}

void print_matrix(matrix_t *matrix) {
    int count = 0;
    double **m_ptr = matrix->matrix;
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

// Обрезка матрицы
void cut_matrix(int col, int row, matrix_t *A, matrix_t *result) {
    int row_to_set = 0;
    int col_to_set;

    s21_create_matrix(A->rows - 1, A->columns - 1, result);
    for (int i = 0; i < A->rows; i++) {
        col_to_set = 0;
        if (i == col) continue;

        for (int j = 0; j < A->columns; j++) {
            if (j == row) continue;
            result->matrix[row_to_set][col_to_set++] = A->matrix[i][j];
        }
        row_to_set++;
    }
}

double count_minor(int col, int row, matrix_t *A) {
    matrix_t cut_m;
    cut_matrix(col, row, A, &cut_m);

    double double_res;
    double_res = 0;

    s21_determinant(&cut_m, &double_res);

    return double_res;

}