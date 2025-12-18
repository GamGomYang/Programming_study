
import sys
# sys.stdin = open("input.txt", "rt")
input = sys.stdin.readline

a , b = map(int , input().split())

arr = list(map(int , input().split()))

arr.sort()
cnt = 0

for i in range (len(arr)):
    if arr[i-1] == arr[i]:
        continue
    else :
        cnt += 1

        if cnt == b:
            print(arr[i])
            break
else:
    print(-1)






