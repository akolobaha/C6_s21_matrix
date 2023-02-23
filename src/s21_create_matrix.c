#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  double *ptr;
  int status = OK;
  if (rows <= 0 || columns <= 0) status = INCORRECT_M;

  if (status == OK) {
    result->matrix =
        malloc(rows * columns * sizeof(double) + rows * sizeof(double *));
    ptr = (double *)(result->matrix + rows);

    if (ptr == NULL) status = CALC_ERROR;
  }

  if (status == OK) {
    for (int i = 0; i < rows; i++) result->matrix[i] = ptr + columns * i;

    result->rows = rows;
    result->columns = columns;
  }

  return status;
}
