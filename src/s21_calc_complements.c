#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  // Проверка на то, что матрицы квадратные
  int status = OK;

  if (!is_matrix_correct(A) || is_matrix_size_positive(*A))
    status = INCORRECT_M;
  else if (A->rows != A->columns)
    status = CALC_ERROR;

  if (status == OK) {
    s21_create_matrix(A->rows, A->columns, result);

    if (A->rows == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor = {0};
          double determinant = 0;
          int x = s21_create_matrix(A->columns - 1, A->rows - 1, &minor);
          get_matrix(i, j, A, &minor);
          s21_determinant(&minor, &determinant);
          result->matrix[i][j] = pow(-1, (i + j)) * determinant;
          if (x == 0) s21_remove_matrix(&minor);
        }
      }
    }
  }

  return status;
}