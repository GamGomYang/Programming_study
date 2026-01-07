import sys
from collections import deque

#sys.stdin = open("input.txt", "rt")

n , m = map(int, input().split())

q = [(pos , val ) for pos, val in enumerate (list(map(int, input().split())))]
#enumerate -> 인덱스로 표기 0,1,2,3 이렇게 나타내는거임
q = deque(q)
cnt = 0

while True:
    cur = q.popleft()
    if any(cur[1]<x[1] for x in q):
        q.append(cur)
    else:
        cnt +=1
        if cur[0] == m :
            print(cnt)
            break



