import sys

# sys.stdin = open("input.txt", "rt")


n = int(input())

for i in range(n):
    arr = list(map(str, input().lower()))

    left = 0
    right = len(arr)-1

    while(left<right):

        if(arr[left]==arr[right]):
            left +=1
            right -=1
        elif(arr[left]!=arr[right]):
            print(f"#{i+1} NO")
            break
    else:
        print(f"#{i+1} YES")

        '''
        
import sys

sys.stdin = open("input.txt", "rt")


n = int(input())

for i in range(n):

    s = input()
    s = s.upper()

    size = len(s)

    for j in range(size//2):
        if s[j] != s[-1-j]:
            print("#%d NO"  %(i+1))
            break
    else:
        print("#%d YES" %(i+1))



        
        '''
        
        


        