#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum status { OK, INCORRECT_M, CALC_ERROR };

enum eq_status { FAILURE, SUCCESS };

#define TOL 0.0000001
//#define SUCCESS 1
//#define FAILURE 0

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int is_matrix_size_positive(matrix_t matrix);
int is_matrix_size_equal(matrix_t *A, matrix_t *B);
int is_matrix_correct(matrix_t *A);
int is_matrix_consistent(matrix_t A, matrix_t B);
int s21_is_empty(matrix_t *matrix);
int compare_doubles(double a, double b);
void fill_matrix_val(matrix_t *matrix, int val);
void print_matrix(matrix_t m);
void get_matrix(int row, int col, matrix_t *A, matrix_t *result);
double count_minor(int col, int row, matrix_t *A);
void cut_matrix(int col, int row, matrix_t *A, matrix_t *result);
