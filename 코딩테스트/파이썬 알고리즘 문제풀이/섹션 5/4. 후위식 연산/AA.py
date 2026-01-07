import sys

#sys.stdin = open("input.txt", "rt")

s = input()
res = 0

stack = []

for x in s:
    if x.isdecimal():
        stack.append(int(x))
    else:
        b = stack.pop()
        a = stack.pop()

        if  x == '+':
            res = a+b
        elif x == '-':
            res = a-b
        elif x == '*':
            res = a*b
        elif x == '/':
            res = a//b

        stack.append(res)

print(stack[0])
        





