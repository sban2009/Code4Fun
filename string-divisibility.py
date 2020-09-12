'''
DIVISIBILITY OF STRINGS:

FIND IF STRING s IS DIVISIBLE BY t
IF YES,
    THEN FIND u, ON REPEATING WHICH WE GET BOTH s AND t
    RETURN LENGTH OF u
ELSE RETURN -1

EXAMPLE:
i/p: s="abcabcabcabc" t="abcabc"
o/p: 3 (AS |u|=|"abc"|=3)
'''


def FSD2(s, t):
    temp = ""
    for i in range(0, int(len(s)/len(t))):
        temp += t
        if(temp == s):
            return True
    return False


def FSD(s, t):
    temp1 = ""
    temp2 = ""
    for i in range(0, int(len(s)/len(t))):
        temp1 += t
        if(temp1 == s):
            for j in range(0, len(t)):
                u = t[0:j+1]
                if(FSD2(t, u)):
                    return len(u)
            return len(t)
    return -1


'''
print(FSD("rbrb","rbrb"))
print(FSD("ababab","abab"))
print(FSD("abcabcabcabc","abcabc"))
>> 2
>> -1
>> 3
'''
