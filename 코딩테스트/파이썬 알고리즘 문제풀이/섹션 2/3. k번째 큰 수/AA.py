
import sys
# sys.stdin = open("input.txt", "rt")
input = sys.stdin.readline

a, b = map(int , input().split())

arr = list(map(int , input().split()))

res = set()
# 중복 제거를 위해서 set을 사용한다.

for i in range(a):
    for j in range(i+1, a):
        for m in range(j+1, a):
            res.add(arr[i]+arr[j]+arr[m])
            #set에 add 한다.
res = list(res)
res.sort(reverse = True)

print(res[b-1])






