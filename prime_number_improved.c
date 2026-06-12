#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define LOWEST_LIMIT 2
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

bool is_prime(int n, bool optimized, int prime_numbers[], int found) {
    return optimized ? is_prime_optimized(n, prime_numbers, found) : is_prime_simple(n);
}

void find_prime_numbers(const int limit, int n, int prime_numbers[]) {
    for (int j = 0; n <= limit; n++)
    {
        bool isPrime = true;
        for (int i = LOWEST_LIMIT; (i * i) < n; i++)
        {            
            if (n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            prime_numbers[j++] = n;
        }
    }  
}

void print_prime_numbers(int primes[], const int len) {
    for (int i = 0; i < len; i++)
    {
        if (i > PRINT_LIMIT)
        {
            break;
        }
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

    int prime_numbers[PRIME_LENGTH];
    int n = LOWEST_LIMIT;

    find_prime_numbers(limit, n, prime_numbers);

    printf("\n------------------------------\n");
    
    print_prime_numbers(prime_numbers, sizeof(prime_numbers) / sizeof(int));

    return 0;
}