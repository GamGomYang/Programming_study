import sys

# sys.stdin = open("input.txt", "rt")

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

m = int(input())

for i in range(m):
    a,b,c = map(int, input().split())
    if b == 0:
        for _ in range(c):
            arr[a-1].append(arr[a-1].pop(0))
    else:
        for _ in range(c):
            arr[a-1].insert(0, arr[a-1].pop())

s=0
e=n

res = 0
for i in range (n):
    for j in range(s,e):
        res += arr[i][j]
    
    if i < n//2:
        s+=1
        e-=1
    else:
        s-=1
        e+=1

print(res)

        




