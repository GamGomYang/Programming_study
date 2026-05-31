# Cut Edge Tech - 조건을 초과 하거나 안맞는 지점을 미리 prunning

import sys
sys.stdin = open('input.txt', 'rt')

def dfs(L , sum):
    global res
    if sum > m:
    # sum 보다 크면 return 함수 종료
        return
    if sum == m :
        if res > L:
            res = L
    else:
        for i in range(n):
            dfs(L+1 , sum + a[i])


if __name__ == "__main__":
    n = int(input())

    a = list(map(int, input().split()))

    m = int(input())

    res = 2147000000

    a.sort(reverse = True)

    dfs(0,0)

    print(res)