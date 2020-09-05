'''
Rotate a given String in specified direction by specified magnitude.

After each rotation make a note of first character of the rotated String, After all rotation are performed the accumulated first character as noted previously will form another string, say FIRSTCHARSTRING.

Check If FIRSTCHARSTRING is an Anagram of any substring of the Original string.

If yes print "YES" otherwise "NO".
'''

def rotator(s,rot,mag):
    if rot=="L":
        Lfirst = s[0 : mag]
        Lsecond = s[mag :]
        return(Lsecond + Lfirst)
    elif rot=="R":
        Rfirst = s[0 : len(s)-mag] 
        Rsecond = s[len(s)-mag : ]
        return(Rsecond + Rfirst)
s = input()
q=int(input())
rot=[]
mag=[]
initials=[]
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
if sorted(substring)==sorted(initial):
    print("YES")
else:
    print("NO")