import sys

#sys.stdin = open("input.txt" , "rt")

n = int(input())

arr = [list(map(int , input().split())) for _ in range(n)]
cnt = 0

dx = [-1 , 0 ,1,0]
dy = [0,1,0,-1]

arr.insert(0, [0]*n)
arr.append([0]*n)

for x in arr:
    x.insert(0,0)
    x.append(0)

for i in range(1, n+1):
    for j in range(1,n+1):
        if all(arr[i][j]>arr[i+dx[k]][j+dy[k]] for k in range(4)):
            cnt+=1

print(cnt)