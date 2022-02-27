'''
find nearest repeated value of an array
e.g. A=[1,2,5,4,2,1,3,3,7,2] will give 3 as the closest repeated value (index 6,7-> distance=0)
'''

A = list(map(int, input.split()))

# hashmap holding key:[latest_index, min_distance] pairs
hm = dict()
n = len(A)

for i in range(0, n):
    # print(hm)
    if A[i] in hm:
        dist = i-hm[A[i]][0]
        hm[A[i]][0] = i
        if dist < hm[A[i]][1]:
            hm[A[i]][1] = dist
    else:
        hm[A[i]] = [i, float('inf')]
min_dist = float('inf')
closest_val = None

# computing closest element
for key in hm:
    if hm[key][1] < min_dist:
        min_dist = hm[key][1]
        closest_val = key
# print(hm)
print(closest_val)
