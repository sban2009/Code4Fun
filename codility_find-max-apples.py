"""
Alice and Bob work in a beautiful orchard. There are N apple trees in the orchard. The apple trees are arranged in a row and they are numbered from 1 to N.
Alice is planning to collect all the apples from K consecutive trees and Bob is planning to collect all the apples from L consecutive trees. They want to choose two disjoint segments (one consisting of K trees for Alice and the other consisting of L trees for Bob) so as not to disturb each other.
What is the maximum number of apples that they can collect?

Write a function:
def solution (A, K, L)
that, given an array A consisting of N integers denoting the number of apples on each apple tree in the row, and integers K and L denoting, respectively, the number of trees that Alice and Bob can choose when collecting, returns the maximum number of apples that can be collected by them, or -1 if there are no such intervals.
For example, given A = [6, 1, 4, 6, 3, 2, 7, 4], K = 3, L = 2, your function should return 24, because Alice can choose trees 3 to 5 and collect 4 + 6 + 3 = 13 apples, and Bob can choose trees 7 to 8 and collect 7 + 4 = 11 apples. Thus, they will collect 13 + 11 = 24 apples in total, and that is the maximum number that can be achieved.

Given A = [10, 19, 15], K = 2, L = 2,
your function should return -1,
because it is not possible for Alice and Bob to choose two disjoint intervals.

Assume that:
• N is an integer within the range [2..100];
• K and L are integers within the range [1..N - 1];
• each element of array A is an integer within the range [1..500].

No time/space constraint
"""


def find_max_apples_solution(A, K, L):
    alice = find_max_apples(A, K, L)
    bob = find_max_apples(A, L, K)
    return max(alice, bob)


def find_max_apples(A, k, l):
    if k + l > len(A):
        return -1
    apples_sum = [0] * len(A)
    apples_sum[0] = A[0]
    for i in range(1, len(A)):
        apples_sum[i] = apples_sum[i - 1] + A[i]
    max_apples = -1
    x, y = 0, 0
    a = 0
    while a + k - 1 < len(A):
        x = apples_sum[a + k - 1] - apples_sum[a - 1] if a > 0 else apples_sum[a + k - 1]
        b = a + k
        while b + l - 1 < len(A):
            y = apples_sum[b + l - 1] - apples_sum[b - 1] if b > 0 else apples_sum[b + l - 1]
            if x + y > max_apples:
                max_apples = x + y
            b += 1
        a += 1
    return max_apples
