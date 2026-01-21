#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

// define a struct Matrix
typedef struct
{
    int size;
    double **data;
} Matrix;

// Memory Management
Matrix create_matrix(int n);
Matrix create_augmented_matrix(int n);
void free_matrix(Matrix m);

// Math Operations
double calculate_determinant(Matrix *m);
void solve_cramer(Matrix *A, double *B);

// Gauss Elimination Methods
void forward_elimination(Matrix *m);

#endif