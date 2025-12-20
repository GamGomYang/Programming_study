import sys

# sys.stdin = open("input.txt", "rt")
n = int(input())
a = list(map(int, input().split()))

ave = round(sum(a)/n)
# round - 반올림 하는 함수 int 형변환과 다름
min = 2147000000

#enumerate -> 리스트의 index와 value둘다 출력
for idx , value in enumerate(a):
    tmp = abs(value - ave)
    if tmp < min:
        min = tmp
        score = value
        res = idx+1

    elif tmp == min:
        if value > score:
            res = idx
            score = value  

print(ave, res)