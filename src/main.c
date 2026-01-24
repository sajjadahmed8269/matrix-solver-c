#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
// Windows-specific headers for terminal control
#ifdef _WIN32
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif

#ifdef _WIN32
#define SYMBOL_SUCCESS "[PASS]"
#define SYMBOL_FAILURE "[FAIL]"
#define SYMBOL_WARN "[WARNING]"
#else
#define SYMBOL_SUCCESS "✓"
#define SYMBOL_FAILURE "❌"
#define SYMBOL_WARN "⚠"
#endif

// ANSI Color codes
#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED "\033[0;31m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_RESET "\033[0m"
#define COLOR_BOLD "\033[1m"

void init_terminal()
{
#ifdef _WIN32
    // 1. Enable UTF-8 Support (for the box symbols ╔ ═ ╗)
    SetConsoleOutputCP(65001);

    // 2. Enable ANSI Escape Sequences (for COLOR_GREEN, COLOR_BOLD, etc.)
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE)
    {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode))
        {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
}

int main(void)
{
    init_terminal(); // Run the fix first!
    // Greetings & Description
    printf(COLOR_GREEN COLOR_BOLD);
    printf("\n ╔═══════════════════════════════════════════════════════╗\n");
    printf(" ║                                                       ║\n");
    printf(" ║                   MATRIX SOLVER                       ║\n");
    printf(" ║                                                       ║\n");
    printf(" ║      Solve NxN Systems of Linear Equations            ║\n");
    printf(" ║                                                       ║\n");
    printf(" ╚═══════════════════════════════════════════════════════╝\n");
    printf(COLOR_RESET "\n");

    // Dimension input & Logic check for n
    char buffer[100];
    int n;
    do
    {
        printf(COLOR_CYAN "Enter the dimension (n) for the n×n system: " COLOR_RESET);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &n) == 1 && n >= 1 && n <= 100)
            {
                break; // Valid Input
            }
        }
        printf(COLOR_RED "%s Invalid Input: Please enter a positive integer between 1 and 100.\n" COLOR_RESET, SYMBOL_FAILURE);

    } while (1);

    printf(COLOR_GREEN "%s Matrix dimension set to: %dx%d\n\n" COLOR_RESET, SYMBOL_SUCCESS, n, n);

    // Check which operation to perform by the user
    printf(COLOR_BOLD COLOR_BLUE "Select an operation:\n" COLOR_RESET);
    printf("  " COLOR_CYAN "1" COLOR_RESET " - Solve system of linear equations\n");
    printf("  " COLOR_CYAN "2" COLOR_RESET " - Calculate matrix determinant\n\n");

    int choice;
    do
    {
        printf(COLOR_CYAN "Enter your choice (1-2): " COLOR_RESET);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &choice) == 1 && choice >= 1 && choice <= 2)
            {
                break; // Valid Input
            }
        }
        printf(COLOR_RED "%s Invalid Input: Please enter 1 or 2.\n" COLOR_RESET, SYMBOL_FAILURE);

    } while (1);

    // Perform the chosen operation
    if (choice == 1)
    {
        // Solve system of equations
        printf(COLOR_BOLD COLOR_BLUE "\n════════════════════════════════════════\n" COLOR_RESET);
        printf(COLOR_BOLD COLOR_BLUE "      SOLVING SYSTEM OF EQUATIONS\n" COLOR_RESET);
        printf(COLOR_BOLD COLOR_BLUE "════════════════════════════════════════\n\n" COLOR_RESET);

        Matrix m = create_augmented_matrix(n);
        if (m.size == 0)
        {
            printf(COLOR_RED "%s Memory allocation failed. Exiting.\n" COLOR_RESET, SYMBOL_FAILURE);
            return 1;
        }

        // Take matrix input from user
        printf(COLOR_CYAN "Enter the Coefficient Matrix A row by row:\n" COLOR_RESET);
        for (int i = 0; i < n; i++)
        {
            printf(COLOR_YELLOW "Row %d" COLOR_RESET ": \n", i + 1);
            for (int j = 0; j < n; j++)
            {
                printf("a%d%d = ", i + 1, j + 1);
                scanf("%lf", &m.data[i][j]);
            }
        }

        printf("\n" COLOR_CYAN "Enter the Constants Vector b:\n" COLOR_RESET);
        for (int i = 0; i < n; i++)
        {
            printf("b%d = ", i + 1);
            scanf("%lf", &m.data[i][n]);
        }

        // Perform Gauss elimination
        printf(COLOR_YELLOW "\nProcessing with Gaussian Elimination...\n" COLOR_RESET);
        if (!forward_elimination(&m))
        {
            printf(COLOR_RED "\n%s SINGULAR MATRIX DETECTED\n" COLOR_RESET, SYMBOL_FAILURE);
            printf(COLOR_RED "   The system has no unique solution.\n" COLOR_RESET);
            printf(COLOR_RED "   (The coefficient matrix is singular/non-invertible)\n" COLOR_RESET);
            free_matrix(m);
            return 1;
        }

        // check solution type
        int solution_type = check_solutions(m);
        printf("\n");
        switch (solution_type)
        {
        case INFINITE_SOLUTIONS:
            printf(COLOR_YELLOW "%s INFINITE SOLUTIONS\n" COLOR_RESET, SYMBOL_WARN);
            printf(COLOR_YELLOW "The system has infinitely many solutions.\n" COLOR_RESET);
            printf(COLOR_YELLOW "(The system has dependent equations)\n" COLOR_RESET);
            free_matrix(m);
            return 1;
        case NO_SOLUTION:
            printf(COLOR_RED "%s NO SOLUTION EXISTS\n" COLOR_RESET, SYMBOL_FAILURE);
            printf(COLOR_RED "The system is inconsistent.\n" COLOR_RESET);
            printf(COLOR_RED "(Contradictory equations detected)\n" COLOR_RESET);
            free_matrix(m);
            return 1;
        case UNIQUE_SOLUTION:
            double *answers = back_substitution(m);
            printf(COLOR_GREEN COLOR_BOLD "%s UNIQUE SOLUTION FOUND\n" COLOR_RESET, SYMBOL_SUCCESS);
            printf(COLOR_BOLD "════════════════════════════════════════\n" COLOR_RESET);
            for (int i = 0; i < n; i++)
            {
                printf(COLOR_GREEN "  x%-2d = %+.5lf\n" COLOR_RESET, i + 1, answers[i]);
            }
            printf(COLOR_BOLD "════════════════════════════════════════\n" COLOR_RESET);
            free(answers);
            free_matrix(m);
            break;
        }

        return 0;
    }
    else if (choice == 2)
    {
        // Calculate determinant
        printf(COLOR_BOLD COLOR_BLUE "\n════════════════════════════════════════\n" COLOR_RESET);
        printf(COLOR_BOLD COLOR_BLUE "      CALCULATING MATRIX DETERMINANT\n" COLOR_RESET);
        printf(COLOR_BOLD COLOR_BLUE "════════════════════════════════════════\n\n" COLOR_RESET);

        Matrix m = create_matrix(n);
        if (m.size == 0)
        {
            printf(COLOR_RED "%s Memory allocation failed. Exiting.\n" COLOR_RESET, SYMBOL_FAILURE);
            return 1;
        }

        // Take matrix input from user
        printf(COLOR_CYAN "Enter the Matrix row by row:\n" COLOR_RESET);
        for (int i = 0; i < n; i++)
        {
            printf(COLOR_YELLOW "Row %d" COLOR_RESET ": \n", i + 1);
            for (int j = 0; j < n; j++)
            {
                printf("a%d%d = ", i + 1, j + 1);
                scanf("%lf", &m.data[i][j]);
            }
        }

        // Calculate determinant
        printf(COLOR_YELLOW "\nCalculating determinant...\n" COLOR_RESET);
        double det = calculate_determinant(&m);

        printf("\n" COLOR_BOLD "════════════════════════════════════════\n" COLOR_RESET);
        printf(COLOR_GREEN COLOR_BOLD "%s DETERMINANT CALCULATED\n" COLOR_RESET, SYMBOL_SUCCESS);
        printf(COLOR_BOLD "════════════════════════════════════════\n" COLOR_RESET);
        printf(COLOR_GREEN "  det(A) = %.5lf\n" COLOR_RESET, det);

        if (det == 0.0)
        {
            printf(COLOR_YELLOW "  %s Matrix is singular (non-invertible)\n" COLOR_RESET, SYMBOL_WARN);
        }
        else
        {
            printf(COLOR_GREEN "  %s Matrix is non-singular (invertible)\n" COLOR_RESET, SYMBOL_SUCCESS);
        }
        printf(COLOR_BOLD "════════════════════════════════════════\n" COLOR_RESET);

        free_matrix(m);
        return 0;
    }

    return 0;
}