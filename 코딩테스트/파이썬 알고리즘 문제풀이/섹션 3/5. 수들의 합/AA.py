import sys

sys.stdin = open("input.txt", "rt")

n, m = map(int, input().split())
arr = list(map(int, input().split()))

cnt = 0
left = 0
res = 0

for right in range(n):
    res += arr[right]
    while res > m :
        res -= arr[left]
        left += 1
    if res == m :
        cnt+=1 

print(cnt)


'''
for i in range(n):
    res =0 
    if arr[i] != m:
        res += arr[i]
        for j in range(i+1 , n):
            res += arr[j]    
            if(res == m):
                cnt +=1
                break
            elif(res > m):
                break
            else:
                continue
    else:
        cnt +=1

print(cnt)

'''