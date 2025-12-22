import sys
# sys.stdin = open("input.txt", "rt")

n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]

max_sum = -2147000000
diagonal_sum_1 = 0
diagonal_sum_2 =0

for i in range (n):
    row_sum = 0
    column_sum = 0
    for j in range(n):
        row_sum += arr[i][j]
        column_sum += arr[j][i]
    max_sum = max(max_sum, row_sum , column_sum) 
    diagonal_sum_1 += arr[i][i]
    diagonal_sum_2 += arr[i][n-1-i]


max_sum = max(max_sum , diagonal_sum_1 , diagonal_sum_2)


print(max_sum)




