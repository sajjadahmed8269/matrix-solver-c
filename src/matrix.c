#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Create a matrix of size n x n
Matrix create_matrix(int n)
{
    Matrix m;
    m.size = n;
    m.data = (double **)malloc(n * sizeof(double *));
    // Handle allocation failure
    if (m.data == NULL)
    {
        m.size = 0;
        return m;
    }
    for (int i = 0; i < n; i++)
    {
        m.data[i] = (double *)malloc(n * sizeof(double));
        // Handle allocation failure
        if (m.data[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(m.data[j]);
            }
            free(m.data);
            m.size = 0;
            m.data = NULL;
            return m;
        }
    }
    return m;
}

// Create a matrix of size n x n+1
Matrix create_augmented_matrix(int n)
{
    Matrix m;
    m.size = n;
    m.data = (double **)malloc(n * sizeof(double *));
    // Handle allocation failure
    if (m.data == NULL)
    {
        m.size = 0;
        return m;
    }
    for (int i = 0; i < n; i++)
    {
        m.data[i] = (double *)malloc((n + 1) * sizeof(double));
        // Handle allocation failure
        if (m.data[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(m.data[j]);
            }
            free(m.data);
            m.size = 0;
            m.data = NULL;
            return m;
        }
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

// Gauss Elimination Method
// forward elimination for gauss elimination method
void forward_elimination(Matrix *m)
{
    for (int j = 0; j < m->size - 1; j++)
    {
        // Partial Pivoting
        int max_row = j;
        for (int i = j + 1; i < m->size; i++)
        {
            if (m->data[i][j] > m->data[max_row][j])
            {
                max_row = i;
            }
        }
        // Swap rows
        if (max_row != j)
        {
            for (int k = 0; k < m->size + 1; k++)
            {
                double temp = m->data[j][k];
                m->data[j][k] = m->data[max_row][k];
                m->data[max_row][k] = temp;
            }
        }
        // Elimination process
        for (int i = j + 1; i < m->size; i++)
        {
            double factor = m->data[i][j] / m->data[j][j];
            for (int k = 0; k < m->size + 1; k++)
            {
                m->data[i][k] = factor * m->data[j][k];
            }
        }
    }
}

// Back substitution
double *back_substitution(Matrix m)
{
    int n = m.size;
    double *answers = (double *)calloc(n, sizeof(double));
    for (int i = n - 1; i >= 0; i--)
    {
        // base case
        if (i == n - 1)
        {
            answers[i] = m.data[i][i] / m.data[i][n];
        }
        else
        {
            double sum = 0;
            for (int j = i + 1; j < n; j++)
            {
                sum += m.data[i][j] * answers[j];
            }
            double b = m.data[i][n] - sum;
            answers[i] = b / m.data[i][i];
        }
    }
    return answers;
}