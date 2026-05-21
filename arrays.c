#include <stdio.h>
#include <stdlib.h>

/*

Goal: Accounting program that Keeps track of money flow in a company

Requirements:
- record the income and expenses by month
- ask the user to enter a new value (positive for income and negative for expenses)
- insert the value in our accounting software
- when the user enters 0, print the whole list of inputs and outputs
*/
int main() {

    printf("Arrays\n");

    printf("Arrays: Working in a poor way\n");

    const int MAX_IO = 5;
    int io_count;
    float io_array[MAX_IO];

    for (io_count = 0; io_count < MAX_IO; io_count++)
    {
        float value;
        printf("Insert an amount of money (0 to end):\n");
        printf("[%d/%d] ", io_count + 1, MAX_IO);
        scanf("%f", &value);

        io_array[io_count] = value;

        if (value == 0)
        {
            break;
        }
    }

    printf("-------------------\n");
    printf("List of operations:\n");
    
    float sum = 0;
    for (int i = 0; i < io_count; i++)
    {
        printf("%d | %9.2f$\n", (i+1), io_array[i]);
        sum += io_array[i];
    }

    printf("-------------------\n");
    printf("Total: %9.2f$\n", sum);

    return 0;
}