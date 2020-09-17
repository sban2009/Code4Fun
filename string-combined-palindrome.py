'''
Given two strings, A and B, of the same length n,
find whether it is possible to cut both strings
at a common point such that the first part of A
and the second part of B form a palindrome.
'''
# for exit
import sys

# method for palindrome checker


def palin(s):
    return s == s[::-1]

# driver code (main)


n = None
# input
A = input("string A: ")
B = input("string B: ")
# unequal or no input
if len(A) != len(B) or n is None:
    print("wrong input")
    sys.exit(1)
else:
    n = len(A)
# iterator variable
i = 0
# possibility variable
possible = False
# loop for checking
while i != n:
    # check if A[till i]+B[after i] is palindrome
    if palin(A[:i]+B[i:n]):
        possible = True
        break
    i += 1
# output
if(possible):
    #print("palindrome is "+A[:i]+B[i:n]+" with cut at position "+str(i))
    print("possible")
else:
    print("not possible")
'''
string A: CAR
string B: BAC
#palindrome is CAC with cut at position 1
possible
'''
