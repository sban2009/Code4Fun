'''
TCS CodeVita7 (2018) Round 1 Problem
String Rotation

Rotate a given String in specified direction by specified magnitude.
After each rotation make a note of first character of the rotated String.
After all rotation are performed the accumulated first character
as noted previously will form another string, say FIRSTCHARSTRING.
Check If FIRSTCHARSTRING is an Anagram of any substring of the Original string.
If yes print "YES" otherwise "NO".

Input the first line contains the original string s.
The second line contains a single integer q.
The ith of the next q lines contains character d[i] denoting direction
and integer r[i] denoting the magnitude.

1<=Length of Original string<=30
1<=q<=10

Example w/ explanation:
carrace
3
L 2
R 2
L 3
NO

FIRSTCHARSTRING = “rcr”, not an anagram of any sub string of original string “carrace”.
'''

# rotate string (s) in (rot) L/R direction by magnitude (mag)
def rotator(s,rot,mag):
    #left rotation
    if rot=="L":
        Lfirst = s[0 : mag]
        Lsecond = s[mag :]
        return(Lsecond + Lfirst)
    #right rotation
    elif rot=="R":
        Rfirst = s[0 : len(s)-mag] 
        Rsecond = s[len(s)-mag : ]
        return(Rsecond + Rfirst)

s = input() #string
q=int(input()) #num of rotations
rot=[] #rotation directions
mag=[] #rotation magnitudes
initials=[] #stores the first characters
for i in range(0,q):
    rot.append(input())
    mag.append(int(input()))
for j in range(0,q):
    initials.append(rotator(s,rot[j],mag[j])[0])
substring = []
for count in range (0,len(s)):
    substring.append(s[count:len(s)])
initial=""
initial=initial.join(initials)
if sorted(substring)==sorted(initial): #anagram (sorting letters give equal strings)
    print("YES")
else:
    print("NO")
