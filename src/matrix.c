#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Create a matrix of size n x n
Matrix create_matrix(int n)
{
    Matrix m;
    m.size = n;
    m.data = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        m.data[i] = (double *)malloc(n * sizeof(double));
    }
    return m;
}

// Free a matrix of size n x n
void free_matrix(Matrix m)
{
    for (int i = 0; i < m.size; i++)
    {
        free(m.data[i]);
    }
    free(m.data);
}

// Calculate the determinant of a matrix
double calculate_determinant(Matrix *m)
{
    if (m->size == 1)
    {
        return m->data[0][0];
    }
    else if (m->size == 2)
    {
        return (m->data[0][0] * m->data[1][1]) - (m->data[0][1] * m->data[1][0]);
    }
}