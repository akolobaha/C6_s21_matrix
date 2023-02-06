#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    double **single_array_matrix;
    double *ptr;
    int status = OK;
    if (rows <= 0 || columns <= 0)
        status = INCORRECT_M;


    if (status == OK) {
        single_array_matrix = malloc(rows * columns * sizeof (double) + rows * sizeof (double*));
        ptr = (double *) (single_array_matrix + rows);

        if (ptr == NULL)
            status = CALC_ERROR;
    }

    if (status == OK) {
        for (int i = 0; i < columns; i++)
            single_array_matrix[i] = ptr + rows * i;

        result->matrix = single_array_matrix;
        result->rows = rows;
        result->columns = columns;
    }

    return status;
}
