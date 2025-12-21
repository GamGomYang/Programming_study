import sys

sys.stdin = open("input.txt", "rt")
'''
arr =[]

for i in range(20):
    arr.append(i+1)

for i in range(10):

    a, b = map(int , input().split())

    left = a-1
    right = b-1

    while(left<right):
        temp = arr[right]
        arr[right] = arr[left]
        arr[left] = temp

        right -=1
        left += 1

for i in arr:
    print(f"{i}", end = ' ' )
    
'''


arr = list(range(21))

for  _ in range(10):
    a, b = map(int, input().split())
    for i in range((b-a+1)//2):
        arr[a+i], arr[b-i] = arr[b-i], arr[a+i]

for x in arr:
    print(x , end = ' ')
