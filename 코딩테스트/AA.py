import sys
sys.stdin = open("input.txt", "rt")
input = sys.stdin.readline
n = int(input())
arr = list(map(int , input().split()))
total = 0
for i in range(n):
    total += arr[i]
mean = round(total / n)
min_diff = 100
for j in range(n):
    diff = abs(arr[j] - mean)
    if diff < min_diff or (diff == min_diff and arr[j] > arr[student]):
        min_diff = diff
        student = j
print(f"{arr[student]} {student+1}")
    

    

















