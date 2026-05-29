#include <stdio.h>
#include <stdlib.h>

#define LEN 10

// Let's write different versions of summing integer elements

// 1. Standard, passing an array as function paremeter, and using a index variable
int sum_arr(int arr[], const int len) {
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum;
}

// 2. Passing an input parameter of type int[] arr is the same as passing a pointer such as -> int *a_pointer
// Here neither the address of the pointer nor the values will change
// So we can make it all constant
int sum_arr_ptr(const int *const p, const int len) {
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += p[i];
    }
    return sum;
}

// 3. Use pointer arithmetic by incrementing a ptr by 1 at each loop process
// It will increment and get the next address in the array of ints

// In this version of the function, we can go further and perform additional operations on our pointers
// We can calculate offsets i.e differences of position between one pointer and another inside our array
// Ex: (p_item - p) is the same as saying -> the (current_element_pointed - first_element)
// Here p is assigned to the address of the 1st element of {1, 4, -3, 2} (the x_array array)
// We calculate offsets (differences) between elements of 4 bytes, so the result of the operation will be / 4
// Conclusion : Running a difference between two pointers gives us the offset between these two pointers
// This result give us how many elements (in a data structure such as an array) there are between two pointers
int sum_ptr_arithmetic(const int *const p, const int len) {
    int sum = 0;
    for (const int *p_item = p; p_item < p + len; p_item++)
    {
        sum += *p_item;
        printf("%ld, %lld, %d\n", p_item - p, (int64_t) p_item , sum);
    }
    return sum;
}

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

    printf("====Pointer arithmetic with Arrays====\n");
    int x_array[LEN] = {1, 4, -3, 2};

    printf("SUM: %d\n", sum_arr(x_array, LEN));
    printf("SUM PTR: %d\n", sum_arr_ptr(x_array, LEN));

    printf("-----------\n");
    int *ptr = x_array;  // same as *ptr = &x_array[0]
    printf("%llx, %lld, %d\n", (uint64_t)ptr, (uint64_t)ptr, *ptr);

    // This will increment the value of the address stored in the pointer by 4
    // i.e the compiler incremented the value of ptr by 4
    // the actual value will be the next array element that lives in that new address
    // it is no longer pointing to the 1st element but to the 2nd one instead
    // array of int type : an int occupies 4 bytes in memory
    // so the compiler will handle address based on the data type we are dealing with
    // so if ptr = ptr + 1 -> increase the address of ptr by 4
    //.   if ptr = ptr + 3 -> increase the address of ptr by 12
    // THIS ALLOWS US TO USE A POINTER AS A SUBSITUTE AS ARRAYS INDEXING VARIABLES
    ptr++;  // same as ptr = ptr + 1
    printf("%llx, %lld, %d\n", (uint64_t)ptr, (uint64_t)ptr, *ptr);
    ptr++;  // same as ptr = ptr + 1
    printf("%llx, %lld, %d\n", (uint64_t)ptr, (uint64_t)ptr, *ptr);


    printf("SUM using pointer arithmetic: %d\n", sum_ptr_arithmetic(x_array, LEN));

    /*
        Some operations are illegal between pointers:
        addition, division, multiplication, modulo

        The operations tolerated are:
        - differences
        - comparisons (<, >)
    */

    return 0;
}