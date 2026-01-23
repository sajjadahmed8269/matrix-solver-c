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

// Gauss Elimination Methods
bool forward_elimination(Matrix *m);
int check_solutions(Matrix m);
double *back_substitution(Matrix m);

#endif