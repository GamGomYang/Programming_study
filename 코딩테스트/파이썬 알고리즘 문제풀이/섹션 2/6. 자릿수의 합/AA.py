'''
#1 - 나머지 (%) 연산과 나누기(//) 연산
import sys
sys.stdin = open("input.txt", "rt")
n = int(input())
arr = map(int, input().split())

max = -2147000000

def digit_sum(x):
    sum = 0
    while x > 0:
        sum += x%10
        x = x//10
        return sum
    
for i in arr:
    total = digit_sum(i)
    if total > max :
        max = total
        res = i

print(i) 

'''

#2 문자열 (str) 사용
import sys
# sys.stdin = open("input.txt", "rt")

n = int(input())
arr = list(map(int , input().split()))

def digit_sum(x):
    sum = 0 
    for i in str(x):
        #str(x) -> str로 변환
        sum += int(i)
    return sum    
max = -2147000000

for x in arr:
    total = digit_sum(x)
    if total > max :
        max = total
        res = x
    
print(res)
