import sys

#1. readline - 한줄 읽어오기
#2. strip - 불필요한 char (\n, ' ' ) 이런거 없애주는 역할을 함


input = sys.stdin.readline
# T - testcase 테스트 케이스로 생각해보기
T = int(input())

# _ : 아무 의미없는 변수
for T in range(T):
    a, b, c,d = map(int, input().split())

    arr = list(map(int, input().split()))

    arr = arr[b-1 : c]

    arr.sort()
    print("#%d %d" %(T+1,arr[d-1]))




