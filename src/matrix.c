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