#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define LOWEST_LIMIT 3
#define HIGHEST_LIMIT 1000000
#define PRIME_LENGTH 100000
#define PRINT_LIMIT 50

/**
 * Program: Prime Numbers Improved
 * 
 * 
 * A Prime Number is number only divisible by 1 and itself (ex: 1, 3, 5, 7, 11, 13, 19 etc...)
 * 
 * GOALS:
 * - find all prime numbers within a given limit (provided by a user)
 * - check that limit < 2 and <= 1 000 000 (one million)
 * - store prime numbers in a 100K array
 * - optimize the program by using stored prime numbers
 * - compare the execution time between the simple version and optimized one
 * - implement printing of found print separately from the algorithm
 * (so that the measured time for resolving primes is isolated from the printing time)
 * - print up to 50 prime numbers
 * 
 * Prime number algorithm:
 * 
 * 1. Simplest version:
 * Given any number n, check whether it is evenly divisible by 
 *  any number between 2 and n, i.e. that the division leaves no remainder
 * 
 * 2. Slightly optimized version:
 * Given any number n, check whether it is evenly divisible by 
 *  any number between 2 and the square root of n, i.e. that the division leaves no remainder
 * 
 * 3. Optimized solution
 * Given any number n, check whether it is evenly divisible by ANY PRIME_NUMBER
 * between 2 and the square root of n
*/

int validate_usr_input(const int limit) {
    if (limit > HIGHEST_LIMIT || limit < LOWEST_LIMIT)
    {
        printf("limit: %d is out of range [%d, %d]. END OF PROGRAM.\n", limit, LOWEST_LIMIT, HIGHEST_LIMIT);
        return EXIT_FAILURE;
    }
    return 1;
}

bool is_prime_simple(int n) {
    const int limit = sqrt(n);
    for (int i = 2; i <= limit; i++)
    {
        if (n % 2 == 0) 
        {
            return false;
        }
    }
    return true;  
}

bool is_prime_optimized(int n, int prime_numbers[], int found) {
    const int limit = sqrt(n);
    for (int i = 0; i <= found && prime_numbers[i] <= limit; i++)
    {
        if (n % prime_numbers[i] == 0)
        {
            return false;
        } 
    } 
    return true;
}

bool is_prime(int n, bool optimized, int prime_numbers[], int found) {
    return optimized ? is_prime_optimized(n, prime_numbers, found) : is_prime_simple(n);
}

int get_prime_numbers(int limit, int prime_numbers[], bool optimized) {
    int found = 0;
    for (int n = 2; n < limit; n++)
    {
        if (is_prime(n, optimized, prime_numbers, found))
        {
            prime_numbers[found] = n;
            found++;
        }
    }
    return found;
}

void print_prime_numbers(int primes[], int len) {
    printf("Found %d prime numbers.\n", len);
    for (int i = 0; i < len && i < PRINT_LIMIT; i++)
    {
        printf("%d, ", primes[i]);
    }
    printf("\n");
}

int main() {
    
    printf("\n\n===Prime Number Improved===\n\n");

    int limit;
    printf("PRIME NUMBER Generator: Enter a limit: ");
    scanf("%d", &limit);
    validate_usr_input(limit);

    printf("\n------------------------------\n");

    int prime_numbers[PRIME_LENGTH];

    // simple version of the algorithm
    int found = get_prime_numbers(limit, prime_numbers, false);
    print_prime_numbers(prime_numbers, found);

    // optimized version of the algorithm
    int found_optimize = get_prime_numbers(limit, prime_numbers, false);
    print_prime_numbers(prime_numbers, found_optimize);

    return 0;
}