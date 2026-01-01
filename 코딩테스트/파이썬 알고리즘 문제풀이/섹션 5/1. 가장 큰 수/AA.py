import sys
#sys.stdin = open("input.txt", "rt")
num , m = map(int , input().split())
num = list(map(int , str(num)))
stack = []

#stack 을 list 자료형으로 만들었음
for x in num:
    while stack and m > 0 and stack[-1] < x:
        stack.pop()
        m -= 1
        stack.append(x)

if m!= 0:
    stack = stack[:-m]

res = ''.join(map(str, stack))
print(res)