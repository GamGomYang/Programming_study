import sys
from collections import deque 

#sys.stdin = open("input.txt", "rt")

n , k = map(int, input().split())
count = 0
queue = deque(range(1, n+1))

while len(queue) >1:
    count +=1
    x = queue.popleft()

    if count == k:
        count = 0 
        continue
    else:
        queue.append(x)

print(queue[0])