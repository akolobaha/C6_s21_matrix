#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

enum status {OK, INCORRECT_M, CALC_ERROR};

#define TOL 0.0000001
#define SUCCESS 1
#define FAILURE 0


int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int is_matrix_size_positive(matrix_t matrix);
int is_matrix_size_equal(matrix_t *A, matrix_t *B);
int compare_doubles(double a, double b);

void fill_matrix(matrix_t *matrix);
void print_matrix(matrix_t *matrix);

void s21_remove_matrix(matrix_t *A);