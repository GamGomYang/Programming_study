import sys
#sys.stdin = open("input.txt", "rt")
from collections import deque

n, m = map(int , input().split())
arr = list(map(int, input().split()))
cnt = 0
arr.sort()
p = deque(arr)

while p:
    if len(p) == 1 :
        cnt +=1
        break

    if p[0]+p[-1]> m:
        p.pop()
        cnt +=1
    else:
        p.popleft()
        p.pop()
        cnt+=1

print(cnt)

        

