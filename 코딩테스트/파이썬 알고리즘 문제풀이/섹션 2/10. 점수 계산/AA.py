import sys

# sys.stdin = open("input.txt", "rt")

n = int(input())


arr = list(map(int , input().split()))
total =0 
plus =0 

for i in range(n):

    if(arr[i]==1):
        plus +=1
        total += plus

    elif(arr[i] == 0):
        plus =0


print(total)

