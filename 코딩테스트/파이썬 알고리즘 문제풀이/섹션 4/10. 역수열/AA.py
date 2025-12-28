'''
solution 1 : count 를 뒤에서 처리

import sys

sys.stdin = open("input.txt","rt")

n = int(input())
arr = list(map(int, input().split()))

seq = [0] * n

for i in range(n):
    cnt = 0
    for j in range(n):
        if seq[j] == 0:
            if cnt == arr[i]:
                seq[j] = i + 1
                break
            cnt += 1

for x in seq :
    print(x , end = ' ')

    
'''


# solution 2 : 정석 풀이

import sys 
#sys.stdin = open("input.txt" , "rt")
n = int(input())
a = list(map(int, input().split()))
seq = [0]*n
for i in range(n):
    for j in range(n):
        if a[i] == 0 and seq[j]==0:
            seq[j] = i+1
            break
        elif seq[j] == 0:
            a[i] -=1
    
for x in seq:
    print(x , end = ' ')