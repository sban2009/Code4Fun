"""
Problem 1: Multiples of 3 or 5
https://projecteuler.net/problem=1
"""


# Naive approach
def sum_of_multiples(limit):
    total = 0
    for i in range(limit):
        if i % 3 == 0 or i % 5 == 0:
            total += i
    return total


# Time Complexity: O(n)
# Space Complexity: O(1)


# Same but one-liner using list comprehension
def sum_of_multiples_short(limit):
    return sum(i for i in range(limit) if i % 3 == 0 or i % 5 == 0)


# Time Complexity: O(n)
# Space Complexity: O(1)


# formulaic approach for better performance
# This approach uses the arithmetic series formula to calculate the sum of multiples of 3,
# 5, and subtracts the sum of multiples of 15 (to avoid double counting).
# The formula for the sum of the first p multiples of n is: n * p * (p + 1) // 2
# where p is the largest integer such that n * p < limit.
def sum_of_multiples_arithmetic(limit):
    def sum_of_multiples_of(n):
        p = (limit - 1) // n
        return n * p * (p + 1) // 2

    return sum_of_multiples_of(3) + sum_of_multiples_of(5) - sum_of_multiples_of(15)


# Time Complexity: O(1), as we are using a constant number of operations.
# Space Complexity: O(1)

if __name__ == "__main__":
    limit = 1000
    # print("Sum of multiples of 3 or 5 below", limit, "is:", sum_of_multiples(limit))
    # print(
    #     "Sum of multiples of 3 or 5 below",
    #     limit,
    #     "using one-liner is:",
    #     sum_of_multiples_short(limit),
    # )
    print(
        "Sum of multiples of 3 or 5 below",
        limit,
        "using arithmetic series is:",
        sum_of_multiples_arithmetic(limit),
    )
