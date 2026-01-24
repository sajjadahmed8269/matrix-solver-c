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

    return 0;
}
