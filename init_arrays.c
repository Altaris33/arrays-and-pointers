#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LEN 5

int main() {

    printf("Arrays Initialization\n");
    printf("=====================\n");

    // At this state arr[] is an array of type int and is not initialized
    // It can contain unpredictable data
    int arr[LEN];

    // 1. init an array by filling values using a loop
    for (int i = 0; i < LEN; i++)
    {
        arr[i] = 1;
    }

    // 2. Init an array when declaring it : using literals
    //.   In this case, the size is not mandatory since the compiler will infer the size by the literals added
    // Array of elem of type int, of 5 elements
    int x[] = {1, 2, 3, 4, 5};

    // here : elems 4, 5 will be = 0 their default values
    int y[LEN] = {1, 2, 3};

    // all 0s
    int z[LEN] = {0};

    //3. Init using designators (we get what is called a sparse array)
    //.  There are made of 0s but some specific places are init with other values, 
    //.  Using designators

    // elem at index 1 = 1 and elem at index 3 = 1, the rest is 0s
    int w[LEN] = {[1] = 1, [3] = 1};
    // elem at index 1 = 3 and elem at last index = 5, the rest is 0s
    int q[LEN] = {[1] = 3, [LEN - 1] = 5};
    // elem 0 and 1 = 5, 4, last three elems init to 3, 2, 1. the rest is 0s
    int t[10] = {[0] = 5, 4, [LEN - 3] = 3, 2, 1};


    printf("Find the size of an array\n");

    // We can find the size programmatically, even when the size argument is not specified at init time
    // 1. Size in memor -> sizeof operator
    //.   x occupies 20 bytes in memory (4 bytes per int element actually)
    printf("sizeof(x) %lu\n", sizeof(x));

    // 2. Size as in the number of elem an array contains : size in bytes/ size in byte of a single elem
    //.   Get the same of each element in the array
    printf("sizeof(int) %lu\n", sizeof(int));
    printf("size of one elem of array(x[0]):  %lu\n", sizeof(x[0]));

    //.  Now the number of elements by dividing
    printf("size in length of the array:  %lu\n\n", sizeof(x) / sizeof(x[0]));

    // Lets' look at another example
    int8_t arr_1[] = {1, 2, 3, 4, 5};

    printf("sizeof(arr_1) %lu\n", sizeof(arr_1));
    printf("sizeof(int8_t) %lu\n", sizeof(int8_t));
    printf("size of one elem of array(arr_1[0]):  %lu\n", sizeof(arr_1[0]));
    printf("size in length of the array:  %lu\n", sizeof(arr_1) / sizeof(arr_1[0]));

    return 0;
}