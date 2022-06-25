"""
Given a matrix (n*n), print the lexicographical ordering of diagonals
e.g.

input =
a a
c b

explanation =
diagonal 1: cc
diagonal 2: ab
diagonal 3: aa

the correct odering is aa,ab,cc => diagonals 3, then 2 and then 1

output =
[3,2,1]

Return an array with the diagonal numbers (bottom-up, left to right)
arranged in lexicographical order
"""


def repeat(s, n):
    """Method to expand a string to a given required length, e.g.
    s="ab", n=5 will result in "ababa", i.e. ab repeated 6 times,
    then trimmed to 5 characters

    Args:
        s (string): given string
        n (int): required length to be attained

    Returns:
        string: expanded string of length n
    """
    return (s * (n // len(s) + 1))[:n]


def solution(matrix):
    l = len(matrix[0])
    # diagonal number list
    diag = [i for i in range(1, 2 * l)]
    # list of letters in each diagonal
    st = ["" for i in range(2 * l - 1)]
    k = 0

    # lower triangle
    # w/ main diagonal
    for r in range(l - 1, -1, -1):
        i, j = r, 0
        while i < l and j < l:
            st[k] += matrix[i][j]
            i += 1
            j += 1
        k += 1

    # upper triangle
    for c in range(1, l):
        i, j = 0, c
        while i < l and j < l:
            st[k] += matrix[i][j]
            i += 1
            j += 1
        k += 1

    d = dict()
    for i in range(len(diag)):
        d[diag[i]] = repeat(st[i], l)

    # sort the dictionary -> make a list of keys
    ans = dict(sorted(d.items(), key=lambda item: item[1])).keys()

    return list(ans)


print(solution([["a", "a"], ["c", "b"]]))
