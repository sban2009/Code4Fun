# Find minimum swaps to satisfy a[i]%3 = i%3 property in a a given array
a = [0, 1, 3, 2, 1]
a_i = []
diff = 0  # difference in a,a_i values
n = len(a)
# hashmaps containing mod 3 values and indices 0(n)
index_hm, value_hm = dict(), dict()
for i in range(0, n):
    # modded value hashmap
    try:
        value_hm[a[i] % 3] += 1
    except:
        value_hm[a[i] % 3] = 1
    a[i] %= 3
    # modded index hashmap
    try:
        index_hm[i % 3] += 1
    except:
        index_hm[i % 3] = 1
    a_i.append(i % 3)
    if a[i] != a_i[i]:
        diff += 1

print(index_hm, value_hm, a, a_i)
# if hashmaps are not equal, rearrangement not possible 0(n)
if index_hm != value_hm:
    exit(1)
# else, find minimum swaps required to make two arrays equal
# https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
def minSwap(arr, n):  # from ^
    ans = 0
    temp = arr.copy()
    temp.sort()
    h = {}  # store indices
    for i in range(n):
        h[arr[i]] = i
    init = 0
    for i in range(n):
        if arr[i] != temp[i]:  # not in right place
            ans += 1
            init = arr[i]
            arr[i], arr[h[temp[i]]] = arr[h[temp[i]]], arr[i]
            # swap with proper place & update indices
            h[init] = h[temp[i]]
            h[temp[i]] = i
    return ans


for i in range(0, n):
    if a[i] != a_i[i]:
        a[i] = a_i.index(a[i])
    else:
        a[i] = i
print(minSwap(a, n))
