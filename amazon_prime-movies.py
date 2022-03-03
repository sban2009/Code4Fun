# find min. no. of sets an array (awards) can be divided into such that couple-wise difference of each element is at most k
# ex: awards=[1,5,4,6,8,9,2], k=3, o/p=3
# [1,2][4,5,6][8,9] with max diff 1,2,1 respectively
# int minimumGroups(int awards[n],int k) => o/p
def max_diff(arr):
    return max(arr) - min(arr)


def minimumGroups(awards, k):
    awards.sort()
    count = 1
    n = len(awards)
    i, j = 0, 1
    while j != n:
        # print(awards[i : j + 1], max_diff(awards[i : j + 1]))
        if max_diff(awards[i : j + 1]) >= k:
            count += 1
            i = j
            j = i + 1
        j = j + 1
    return count


def main():
    awards = [1, 5, 4, 6, 8, 9, 2]
    k = 3
    print(minimumGroups(awards, k))


if __name__ == "__main__":
    main()
