import sys
from collections import defaultdict

#sys.stdin = open("input.txt", "rt")

a= input()
b= input()

str1 = dict()
str2 = dict()

for x in a:
    str1[x] = str1.get(x,0)+1
for x in b:
    str2[x] = str2.get(x,0)+1

for i in str1.keys():
    if i in str2.keys():
        if str1[i] != str2[i]:
            print("NO")
            break
    else:
        print("NO")
        break
else:
    print("YES")


'''
p = defaultdict(int)
q = defaultdict(int)

word1 = input()
word2 = input()

for x in word1[0:]:
    p[x] += 1

for y in word2[0:]:
    q[y] +=1


if p == q :
    print("YES")
else:
    print("NO")
'''