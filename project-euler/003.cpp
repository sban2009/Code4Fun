/*
Problem 3: Largest Prime Factor
https://projecteuler.net/problem=3
*/
#include <iostream>
#include <cmath>
using namespace std;

// Naive approach
long long largestPrimeFactor(long long n)
{
    long long maxPrime = -1;

    // Check for number of 2s that divide n
    while (n % 2 == 0)
    {
        maxPrime = 2;
        n /= 2;
    }

    // n must be odd at this point, so we can skip even numbers
    for (long long i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            maxPrime = i;
            n /= i;
        }
    }

    // This condition is to check if n is a prime number greater than 2
    if (n > 2)
        maxPrime = n;

    return maxPrime;
}

// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)

// Sieve of Eratosthenes approach (NOT SUITABLE for large n)
/*
long long largestPrimeFactorSieveOfEratosthenes(long long n)
{
    long long maxPrime = -1;
    bool isPrime[n + 1];
    fill(isPrime, isPrime + n + 1, true);

    for (long long p = 2; p * p <= n; p++)
    {
        if (isPrime[p])
        {
            for (long long i = p * p; i <= n; i += p)
            {
                isPrime[i] = false;
            }
        }
    }

    for (long long p = 2; p <= n; p++)
    {
        if (isPrime[p] && n % p == 0)
        {
            maxPrime = p;
        }
    }

    return maxPrime;
}
*/

// Time Complexity : O(n log log n)
// Space Complexity : O(n)

int main()
{
    long long number = 600851475143; // input
    cout << "Largest prime factor of " << number << " is: " << largestPrimeFactor(number) << endl;
    // cout << "Largest prime factor of " << number << " using Sieve of Eratosthenes is: " << largestPrimeFactorSieveOfEratosthenes(number) << endl; // segmentation fault for large n.
    return 0;
}
