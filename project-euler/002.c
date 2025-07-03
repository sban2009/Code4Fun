/*
Problem 2: Even Fibonacci Numbers
https://projecteuler.net/problem=2
*/
#include <stdio.h>
long long int fibonacciSumRecursive(int number1, int number2, int limit)
{
    if (number2 > limit)
        return 0;
    return (number2 % 2 == 0 ? number2 : 0) + fibonacciSumRecursive(number2, number1 + number2, limit);
}
int main()
{
    printf("Sum of even Fibonacci series terms till 4 million: ");
    printf("%lld\n", fibonacciSumRecursive(1, 2, 4000000));
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(log n)