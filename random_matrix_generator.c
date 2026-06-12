#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_ROWS 2
#define MAX_ROWS 10
#define MIN_COLS 2
#define MAX_COLS 10
#define LOWEST_LIMIT 1
#define HIGHEST_LIMIT 1000

/**
 * Program: Generate a random matrix and displays it 
 * - in direct form
 * - in transposed form
 * 
 * Goals:
 * - Generate a random matrix with rows and columns given by the user
 * - Check that rows is <= 1 <= 10, same for columns
 * - The generated matrix must have values ranging from 0 to a limit provided by the user
 * - The maximum value allowed for the limit is 1000 : check that 1 <= limit <= 1000
 * - Display the matrix in both direct and transposed forms
 * 
 * Hints: 
 * - To generate a random number with a given limit, we may need to use the modulo operator
 */

/*
10 % 2 = 0
10 % 3 = 1
10 % 4 = 2
10 % 5 = 0
10 % 6 = 4
10 % 7 = 3
10 % 8 = 2
10 % 9 = 1
10 % 10 = 0
10 % 11 = 10
10 % 12 = 10
...
*/

void generate_matrix(const int rows, const int cols, int matrix[rows][cols], int upper_bound)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % (upper_bound + 1);
        }
    }   
}

void display(int rows, int cols, int matrix[rows][cols], bool transposed) {
    if (!transposed)
    {
        printf("\n-------Direct matrix-------\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                printf("%4d", matrix[i][j]);
            }
            printf("\n");
        }
    } else
    {
        printf("\n-------Transposed matrix-------\n");
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                printf("%4d ", matrix[j][i]);
            }
            printf("\n");
        }
    }
}

void displayTernary(int rows, int cols, int matrix[rows][cols], bool transposed) {
    printf(transposed ? "\n-------Transposed matrix-------\n" : "\n-------Direct matrix-------\n"); 
    for (int i = 0; (transposed ? i < cols: i < rows); i++)
    {
        for (int j = 0; (transposed ? j < rows: j < cols); j++)
        {
            printf("%4d ", (transposed ? matrix[j][i] : matrix[i][j]));
        }
        printf("\n");
    } 
}

int main() {
    
    printf("===Random Matrix Generator===\n");

    int rows, cols, upper_bound;

    printf("Enter a nb of rows for the matrix: [MIN ROWS: %d, MAX ROWS: %d]: ", MIN_ROWS, MAX_ROWS);
    scanf("%d", &rows);

    if (rows > MAX_ROWS || rows < MIN_ROWS)
    {
        printf("Nb of rows %d out of bounds. MIN and MAX are : [%d, %d]\n", rows, MIN_ROWS, MAX_ROWS);
        return EXIT_FAILURE;
    }

    printf("Enter a nb of columns for the matrix: [MIN COLS: %d, MAX COLS: %d]: ", MIN_COLS, MAX_COLS);
    scanf("%d", &cols);
    if (cols > MAX_COLS || cols < MIN_COLS)
    {
        printf("Nb of columns %d out of bounds. MIN and MAX are : [%d, %d]\n", rows, MIN_COLS, MAX_COLS);
        return EXIT_FAILURE;
    }

    printf("Enter a boundary for the matrix values: [%d - %d]: ", LOWEST_LIMIT, HIGHEST_LIMIT);
    scanf("%d", &upper_bound);
    if (upper_bound > HIGHEST_LIMIT || upper_bound < LOWEST_LIMIT)
    {
        printf("Limit %d specified is out of bounds. MIN and MAX are : [%d, %d]\n", upper_bound, LOWEST_LIMIT, HIGHEST_LIMIT);
        return EXIT_FAILURE;
    }

    int matrix[rows][cols];

    // Seed used to get a random number generation for every program run
    // Time elapsed from Epoch compared to the time the program has run 
    // a call to time(NULL) -> gets the time in milliseconds since a 1970 01 01 (also known as Epoch)
    srand(time(NULL));
    generate_matrix(rows, cols, matrix, upper_bound);

    // test calls to display the matrix
    display(rows, cols, matrix, false);
    display(rows, cols, matrix, true);

    displayTernary(rows, cols, matrix, false);
    displayTernary(rows, cols, matrix, true);
    displayTernary(rows, cols, matrix, false);

    return 0;
}