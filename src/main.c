#include <stdio.h>
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
    int n;
    do
    {
        printf("Enter the dimension (n) for the n x n system of equations (e.g., 3 for a 3x3 matrix): ");
        if (scanf("%d", &n) != 1)
        {
            printf("Invalid Input: Please enter a valid number (1 or greater).\n\n");
            while (getchar() != '\n')
                ;
        }
        else if (n < 1)
        {
            printf("Invalid Dimension: Please enter a positive integer (1 or greater).\n\n");
        }
        else
        {
            break;
        }
    } while (1);

    return 0;
}