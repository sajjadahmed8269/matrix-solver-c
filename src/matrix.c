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
    else
    {
        double det = 0;
        int sign = 1;
        for (int col = 0; col < m->size; col++)
        {
            // create matrix of size n-1
            Matrix sub = create_matrix(m->size - 1);
            // fill the sub_matrix
            for (int i = 1; i < m->size; i++)
            {
                int sub_col = 0;
                for (int j = 0; j < m->size; j++)
                {
                    if (j == col)
                    {
                        continue; // skips the column
                    }
                    sub.data[i - 1][sub_col] = m->data[i][j];
                    sub_col++;
                }
            }
            // Add determinants together
            det += sign * m->data[0][col] * calculate_determinant(&sub);
            // change the sign
            sign = -sign;
            // free sub matrix
            free_matrix(sub);
        }
        return det;
    }
}