import sys

# sys.stdin = open("input.txt", "rt")

n = int(input())

max = -2147000000

for i in range(n):
    arr = list(map(int, input().split()))
    a = [0]*(6+1)
    cnt = 0
    total = 0

    for j in arr :
        a[j] +=1

    for j in range(1,7):
        if a[j] == 3:
            total += 10000 + 1000*j
        elif a[j] == 2:
            total += 1000+100*j
        elif a[j] == 1:
            total += 100*j
    
    if total > max :
        max = total

print(max)
