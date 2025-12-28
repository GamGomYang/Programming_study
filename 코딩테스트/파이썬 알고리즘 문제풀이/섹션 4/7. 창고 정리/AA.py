import sys

#sys.stdin = open("input.txt", "rt")

l = int(input())
arr = list(map(int, input().split()))
m = int(input())

arr.sort()

for _ in range(m):
    arr[0] +=1
    arr[l-1] -=1
    arr.sort()

print(arr[l-1] - arr[0])


