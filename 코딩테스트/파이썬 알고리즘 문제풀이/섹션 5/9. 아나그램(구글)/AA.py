import sys
from collections import defaultdict


#sys.stdin = open("input.txt", "rt")

a = input()
b = input()

'''
dict로 하려면? get을 쓴다 
str = dict()
str[x] = str1.get(x,0) + 1
defaultdict에서는 +1 이아니라 +=1을 해야한다. 
'''

str1 = defaultdict(int)
str2 = defaultdict(int)

for x in a :
    str1[x] +=1

for s in b :
    str2[s] +=1

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
