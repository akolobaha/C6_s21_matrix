#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (!is_matrix_size_equal(A, B)) status = CALC_ERROR;

  if (!is_matrix_correct(A) || !is_matrix_correct(B)) status = INCORRECT_M;

  //    fill_matrix_val(result, 0);

  if (status == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return status;
}