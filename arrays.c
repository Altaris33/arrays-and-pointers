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

    // let's see a case where using an array could be useful
    // let's imagine a solution without an array and see the limitations
    // need for as many variables as need to store our inputs/outputs
    // we will store a bunch of variables of the same type
    const int MAX_IO = 5;
    int io_count = 0;
    float io_1, io_2, io_3, io_4, io_5;

    while (io_count >= 0 && io_count < MAX_IO)
    {
        float value;
        printf("Insert an amount of money (0 to end):\n");
        printf("[%d/%d] ", io_count + 1, MAX_IO);
        scanf("%f", &value);

        if (value == 0)
        {
            break;
        }
        io_count++;

        // assign the value entered by the user to the corresponding variables
        // the amount of code gets messy/and difficult to maintain
        // if we have to store a lot of values (100, 200...), the code will get huge
        // so it is not a scalable solution
        switch (io_count)
        {
        case 1:
            io_1 = value;
            break;
        case 2:
            io_2 = value;
            break;
        case 3:
            io_3 = value;
            break;
        case 4:
            io_4 = value;
            break;
        case 5:
            io_5 = value;
            break;
        default:
            printf("Unexpected value.");
            return -1;
        }
    }

    printf("-------------------\n");
    printf("List of operations:\n");
    
    // messy code also, hard to maintain
    switch (io_count)
    {
    case 5:
        printf("5 | %9.2f$\n", io_5);
    case 4:
        printf("4 | %9.2f$\n", io_4);
    case 3:
        printf("3 | %9.2f$\n", io_3);
    case 2:
        printf("2 | %9.2f$\n", io_2);
    case 1:
        printf("1 | %9.2f$\n", io_1);
        break;                
    default:
        printf("Nothing to print.\n");
        break;
    }

    // print the total

    return 0;
}