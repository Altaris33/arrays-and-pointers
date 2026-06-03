#include <stdio.h>
#include <stdlib.h>

#define LEN 5

/**
 * From the C11 standard: Possibility to create variable length arrays
 */
void array_maker(int len) {

    // We cannot initialize a variable sized array directly
    // We can use techniques such as for loops to add values to the array
    int vla[len];
    for (int i = 0; i < len; i++)
    {
        vla[i] = i;
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ", vla[i]);
    }
    printf("\n");
}

int main() {

    printf("===Variable-sized arrays: Arrays===\n");

    // An array is a variable-sized object in C
    // So to be able to define and init an array
    // 1. Case when the needed size of the array is knonwn: we can define
    //    a macro defined using #define with a value associated with it or an int variable
    //    but not a constant
    // 2. Case when the size is not known
    //    Or when the program may change the size of the array each time it is run

    // 1. Fixed size array
    int array[LEN] = {1, 2, 3};

    // Printing the array elements
    for (int i = 0; i < LEN; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    // 2. Variable length array
    while (1)
    {
        int input;
        printf("Enter a size for the array making: ");
        scanf("%d", &input);
        if (input < 1)
        {
            break;
        }
        array_maker(input);
    }
    
    
    printf("\n");
   
    return 0;
}