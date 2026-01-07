import sys
from collections import deque
#sys.stdin = open("input.txt", "rt")

arr = list(map(str , input()))
n = int(input())


for i in range(n):
    plan = input()
    dq = deque(arr)
    for x in plan:
        if x in dq:
            if x!=dq.popleft():
                print(f"#{i+1} NO")
                break

    else:
        if len(dq) == 0:
            print(f"#{i+1} YES")
        else:
            print(f"#{i+1} NO")
        



