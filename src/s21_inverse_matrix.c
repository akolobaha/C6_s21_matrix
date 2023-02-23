#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (!is_matrix_correct(A)) {
    status = INCORRECT_M;
  } else if (A->rows != A->columns) {
    status = CALC_ERROR;
  } else {
    double det;

    status = s21_create_matrix(A->rows, A->columns, result);
    if (status == OK && A->rows) {
      s21_determinant(A, &det);

      if (fabs(det) < TOL) {
        status = CALC_ERROR;
      } else if (A->rows == 1) {
        result->matrix[0][0] = 1.0 / A->matrix[0][0];
      } else {
        matrix_t tmp1 = {0};
        s21_calc_complements(A, &tmp1);
        matrix_t tmp = {0};
        s21_transpose(&tmp1, &tmp);
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = tmp.matrix[i][j] / det;
          }
        }
      }
    }
  }

  return status;
}
