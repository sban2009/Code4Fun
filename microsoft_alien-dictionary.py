# input: dictionary order of words in alien dictionary: ["wrt","wrf","er","ett","rftt"]
# find the letter order

# input list
words = ['wrt', 'wrf', 'er', 'ett', 'rftt']

n = len(words)
nextval = dict()
for i in range(0, n):
    for j in range(i + 1, n):
        for (c1, c2) in zip(words[i], words[j]):
            if c1 != c2:
                if c1 in nextval:
                    if c2 not in nextval[c1]:
                        nextval[c1].append(c2)
                else:
                    nextval[c1] = [c2]
                break
# print(nextval)

ptr = words[0][0]
res = [ptr]
while len(res) != n:
    res.append(nextval[ptr][0])
    if len(res) != n:
        ptr = nextval[ptr][0]
    # print(ptr)

# output: string with letter order
print(''.join(map(str, res)))
# here, ans = w,e,r,t,f or "wertf"