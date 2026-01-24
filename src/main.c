#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    // Greetings & Description
    printf("\033[0;32m");
    printf(" __  __       _        _      ____       _                \n");
    printf("|  \\/  | __ _| |_ _ __(_)_  _/ ___|  ___| |_   _____ _ __ \n");
    printf("| |\\/| |/ _` | __| '__| \\ \\/ / \\___ \\ / _ \\ \\ \\ / / _ \\ '__|\n");
    printf("| |  | | (_| | |_| |  | |>  <  ___) |  __/ |\\ V /  __/ |   \n");
    printf("|_|  |_|\\__,_|\\__|_|  |_/_/\\_\\|____/ \\___|_| \\_/ \\___|_|   \n");
    printf("\033[0m");
    printf("\nThis tool solves NxN systems using Gauss elimination method.");
    printf("\n------------------------------------------------------------\n\n");

    // Dimension input & Logic check for n
    char buffer[100];
    int n;
    do
    {
        printf("Enter the dimension (n) for the n x n system of equations (e.g., 3 for a 3x3 matrix): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &n) == 1 && n >= 1)
            {
                break; // Valid Input
            }
        }
        printf("Invalid Input: Please enter a positive integer (1 or greater).\n\n");

    } while (1);

    // Check which operation to perform by the user
    printf("Select an operation:\n");
    printf("1. Solve system of equations\n");
    printf("2. Calculate determinant\n");

    int choice;
    do
    {
        printf("Enter your choice (1-2): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &choice) == 1 && choice >= 1 && choice <= 2)
            {
                break; // Valid Input
            }
        }
        printf("Invalid Input: Please enter a number between 1 and 2.\n\n");

    } while (1);

    // Perform the chosen operation
    // solve system of equations
    if (choice == 1)
    {
        printf("\nSolving system of equations...\n");
        Matrix m = create_augmented_matrix(n);
        if (m.size == 0)
        {
            printf("Memory allocation failed. Exiting.\n");
            return 1;
        }

        // Take matrix input from user
        printf("Enter the Matrix A row by row:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("Enter the value of a%d%d: ", i + 1, j + 1);
                scanf("%lf", &m.data[i][j]);
            }
        }
        printf("Enter the constants vector b:\n");
        for (int i = 0; i < n; i++)
        {
            printf("Enter the value of b%d: ", i + 1);
            scanf("%lf", &m.data[i][n]);
        }

        // Perform Gauss elimination
        if (!forward_elimination(&m))
        {
            printf("The system has no unique solution (singular matrix).\n");
            free_matrix(m);
            return 1;
        }

        // check solution type
        int solution_type = check_solutions(m);
        switch (solution_type)
        {
        case INFINITE_SOLUTIONS:
            printf("The system has infinitely many solutions.\n");
            free_matrix(m);
            return 1;
        case NO_SOLUTION:
            printf("The system has no solution.\n");
            free_matrix(m);
            return 1;
        case UNIQUE_SOLUTION:
            double *answers = back_substitution(m);
            printf("\nThe unique solution is:\n");
            for (int i = 0; i < n; i++)
            {
                printf("x%d = %.6lf\n", i + 1, answers[i]);
            }
            free(answers);
            free_matrix(m);
            break;
        }

        return 0;
    }

    // calulate determinant
    else if (choice == 2)
    {
        printf("\nCalculating determinant...\n");
        Matrix m = create_matrix(n);
        if (m.size == 0)
        {
            printf("Memory allocation failed. Exiting.\n");
            return 1;
        }

        // Take matrix input from user
        printf("Enter the Matrix A row by row:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("Enter the value of a%d%d: ", i + 1, j + 1);
                scanf("%lf", &m.data[i][j]);
            }
        }

        double det = calculate_determinant(&m);
        printf("\nThe determinant of the matrix is: %.6lf\n", det);
        free_matrix(m);
        return 0;
    }
}
