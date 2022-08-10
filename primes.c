/*
* Simple program to search for prime numbers from 2 to 100 using the Sieve of Eratosthenes
*
* To compile: gcc -o primes primes.c
*/
#include <stdio.h>

#define PRIMELIMIT 100
// Array dimension must be PRIMELIMIT + 1
#define ARRAYSIZE 101

unsigned char number_set[ARRAYSIZE];

int  main()
{

  int i, j;      // loop variables
  int count = 0; // Count of number of primes found

  // Initialize array
  for (i = 1; i < PRIMELIMIT + 1; i++)
  {
    // Value of 0 indicates not prime
    // All numbers are possible primes until sieved.
    number_set[i] = 1;
  }

  printf("\r\nSearching for prime numbers from 2 to %d.\r\n\r\n", PRIMELIMIT);

  for (i = 2; i < PRIMELIMIT + 1; i++)
  {
    // Test i to see if value of i is prime (not prime when i == 0)
    if (number_set[i] == 1)
    {
      // Value of i is not a multiple of a previous prime, so i is prime
      printf("%d ", i);
      count++;
      // loop incrementing j by steps of current value of i
      for (j = i; j < PRIMELIMIT + 1; j += i)
      {
        // Mark all multiples of i as NOT prime
        number_set[j] = 0;
      }
    } 
  }

  printf("\r\n\r\nFound %d prime numbers.\r\n\r\n", count);

  return 0;
}
