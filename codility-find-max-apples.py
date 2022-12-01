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
    a = find_max_apples(A, K, L)
    b = find_max_apples(A, L, K)
    return max(a, b)


def find_max_apples(A, k, l):
    if k + l > len(A):
        return -1
    sum_app = [0] * len(A)
    sum_app[0] = A[0]
    for i in range(1, len(A)):
        sum_app[i] = sum_app[i - 1] + A[i]
    max_app = -1
    x, y = 0, 0
    a = 0
    while a + k - 1 < len(A):
        if a > 0:
            x = sum_app[a + k - 1] - sum_app[a - 1]
        else:
            x = sum_app[a + k - 1]
        b = a + k
        while b + l - 1 < len(A):
            if b > 0:
                y = sum_app[b + l - 1] - sum_app[b - 1]
            else:
                y = sum_app[b + l - 1]
            if x + y > max_app:
                max_app = x + y
            b += 1
        a += 1
    return max_app
