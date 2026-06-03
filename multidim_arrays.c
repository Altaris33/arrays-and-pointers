#include <stdio.h>
#include <stdlib.h>

#define LEN 5
#define N_ROWS 3
#define N_COLS 4
#define N_LAYERS 5

int main() {

    printf("===Multidimensional Arrays===\n");

    // 1D array
    int array[LEN] = {1, 2, 3};

    // Usually a 2D array is referred to as a matrix
    // Init a 2D array 
    // We need two layers of curly braces
    int matrix[N_ROWS][N_COLS] = // the number of elements (n) = N_ROWS * N_COLS
    {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
    }; 

    // Usually a 3D array is referred to as a tensor
    // Init a 3D array 
    // We need three layers of curly braces
    int tensor[N_LAYERS][N_ROWS][N_COLS] = // the number of elements (n) = N_LAYERS * N_ROWS * N_COLS 
    {
        {
            {111, 112, 113, 114},
            {121, 122, 123, 124},
        },
        {
            {211, 212, 213, 214},
            {221, 222, 223, 224},
        },
        // Just like 1D arrays, we can use designators for multi-dimensional arrays to init element at specific indexes
        [N_LAYERS - 1][N_ROWS - 1][N_COLS - 1] = 555,
    }; 

    // Printing the arrays

    // 1D
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n\n");
    
    
    // 2D : nested for loop 
    for (int i = 0; i < N_ROWS; i++)
    {
        for (int j = 0; j < N_COLS; j++)
        {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    
    // 3D: for loop with three layers
    for (int l = 0; l < N_LAYERS; l++)
    {
        for (int i = 0; i < N_ROWS; i++)
        {
            for (int j = 0; j < N_COLS; j++)
            {
                printf("%3d ", tensor[l][i][j]);
            }
            printf("\n");

        }
        printf("\n");
    }
    
    printf("\n");
   
    return 0;
}