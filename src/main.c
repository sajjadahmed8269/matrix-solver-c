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

    return 0;
}