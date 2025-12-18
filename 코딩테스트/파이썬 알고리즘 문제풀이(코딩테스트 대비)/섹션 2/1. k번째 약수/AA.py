import sys
#sys.stdin = open("input.txt", "rt")
#map 함수를 써서 int형으로 받기
n, k = map(int , input().split())

cnt = 0

#for문 range(1,n+1)
for i in range(1,n+1):
    if n%i == 0:
        cnt+=1
    if cnt == k :
        print(i)
        break
else:
    #for else문이 있다 예외처리
    print(-1)
