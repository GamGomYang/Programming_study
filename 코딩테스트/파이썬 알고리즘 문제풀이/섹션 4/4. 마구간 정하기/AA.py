import sys

#sys.stdin = open("input.txt", "rt")
def Count(len):
    cnt = 1
    ep = arr[0]
    for i in range(1, n ):
        if arr[i] - ep >= len:
            cnt +=1
            ep = arr[i]
    return cnt

n, m = map(int, input().split())
arr = []
res = 0
for i in range (n):
    arr.append(int(input()))

arr.sort()

lt = 1
rt = arr[n-1]

while lt <= rt:
    mid = (lt + rt )//2

    if Count(mid) >= m:
        res = mid
        lt = mid +1
    else:
        rt = mid -1

print(res)


