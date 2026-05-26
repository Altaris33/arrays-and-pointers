#include <stdio.h>
#include <stdlib.h>

int main() {


    printf("Pointers & Arrays\n");
    printf("-------------------\n");

    int x[] = {9, 8, 7, 6, 5};

    // 1. Printing all elements inside the array
    // using a for loop
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
    {
        printf("x[i]: %d\n", x[i]);
    }

    // 2. Accessing an element of the array indirectly using a pointer
    // Let's recall:
    /*
        - Arrays are item ordered collections
        - A pointer is a variable that holds the address of another data
        - The concepts of arrays and pointers are deeply intertwined
    */

    // 2a. Accessing a single element of an array using a pointer
    printf("Access an element of x through a pointer:\n");
    int *p = &x[2];
    printf("x[2]: %d, *p: %d\n", x[2], *p);

    // 2b. Updating a single element of an array using a pointer
    //.    Technique: Derefence the pointer using * to update what's stored in the address the pointer stores
    *p = 0;
    printf("x[2]: %d, *p: %d\n", x[2], *p);

    // 3. Get the address of an array
    //.   We can get the address of the first element of the array
    //.   In C an array identifier (its variable name) is nothing more than a label which indicates the starting address of that array
    //.   So getting &x[0] = &x
    printf("Address of the x[] array: \n");
    printf("&x[0] %llx\n", (uint64_t) &x[0]);
    printf("&x    %llx\n", (uint64_t) &x);

    // 4. Define an alias to an array using a pointer
    //.   Here are two possible ways of doing so
    //int *alias = x;
    //int *alias = &x[0];

    // But let's use our formerly define pointer from above to do it
    p = x;

    // As comparison:
    //  - we can access elements directly using the indexing on the array
    //  - we can access eleemnts indirectly using the pointer
    printf("Display x[] through the pointer:\n");
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
    {
        printf("index: %d -> x[i]: %d, p[i]: %d\n", i, x[i], p[i]);
    }

    // 5. Set each element of the array using the pointer indirectly
    printf("Set all elements of x[] through the pointer:\n");
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
    {
        p[i] = i;
        printf("index: %d -> x[i]: %d, p[i]: %d\n", i, x[i], p[i]);
    }

    printf("-------------------\n");


    return 0;
}