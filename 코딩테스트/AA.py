import sys
from collections import defaultdict

#sys.stdin = open("input.txt", "rt")

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