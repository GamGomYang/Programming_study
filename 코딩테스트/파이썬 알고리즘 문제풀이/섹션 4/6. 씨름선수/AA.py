import sys

#sys.stdin = open("input.txt", "rt")

n = int(input())

person = []

for i in range(n):
    t , w = map(int , input().split())
    person.append((t,w))

person.sort(key = lambda x :(x[1], x[0]), reverse =True)
max_tall = 0
cnt =0
for x in person:
    if max_tall < x[0]:

        cnt +=1 
        max_tall = x[0]

print(cnt)   

