'''
Given an integer n, return the next bigger permutation of its digits.
If n is already in its biggest permutation, rotate to the smallest permutation.

case 1
n=	5342310
ans=5343012

case 2
n=		543321
ans=	123345
'''

n = 5342310  # case 1
# n = 543321  # case 2
a = list(map(int, str(n)))
i = len(a)-2
# finding i such that a[i]...a[n-1] is decreasing suffix
while a[i] >= a[i+1]:
    i -= 1
    if i == 0:
        # print('case 2')
        a.reverse()
        print(''.join(map(str, a)))
        exit(0)
# print(i,a[i])
# finding j such that a[j]>a[i] and swapping them
for j in range(i+1, len(a)):
    if a[j] > a[i]:
        a[i], a[j] = a[j], a[i]
        break
# reversing the decreasing suffix to make it increasing
a[i+1:] = reversed(a[i+1:])
# print('case 1')
print(''.join(map(str, a)))
exit(0)