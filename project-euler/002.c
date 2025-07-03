/*
Problem 2: Even Fibonacci Numbers
https://projecteuler.net/problem=2
*/
#include <stdio.h>
#define MAX 4000000
#define ll long long int

ll fibonacciEvenSumRecursive(ll number1, ll number2, ll limit)
{
    if (number2 > limit)
        return 0;
    return (number2 % 2 == 0 ? number2 : 0) + fibonacciEvenSumRecursive(number2, number1 + number2, limit);
}

// Time Complexity: O(log n)
// Space Complexity: O(log n)

ll fibonacciEvenSumIterative(ll a, ll b, ll limit)
{
    ll sum = 0;
    ll number1 = a, number2 = b;
    while (number2 <= limit)
    {
        if (number2 % 2 == 0)
            sum += number2;
        ll nextNumber = number1 + number2;
        number1 = number2;
        number2 = nextNumber;
    }
    return sum;
}

// Time complexity: O(n)
// Space complexity: O(1)

int main()
{
    printf("Sum of even Fibonacci series terms till 4 million: ");
    printf("%lld\n", fibonacciEvenSumRecursive(1, 2, MAX));
    // printf("%lld\n", fibonacciEvenSumIterative(1, 2, MAX));
    return 0;
}