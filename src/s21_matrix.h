#include <stdlib.h>
#include <stdio.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

enum status {OK, INCORRECT_M, CALC_ERROR};


int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int is_matrix_size_negative(matrix_t matrix);

void fill_matrix(matrix_t *matrix);
void print_matrix(matrix_t *matrix);

void s21_remove_matrix(matrix_t *A);