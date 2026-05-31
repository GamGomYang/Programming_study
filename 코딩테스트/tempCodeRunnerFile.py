import sys
def dfs(L , sum):
    global res
    if sum > m:
        return
    if sum == m :
        if res < L :
            res = L
    else:
        for i in range(n):
            dfs(L+1 , sum + a[i])


if __name__ == "__main__":
    n = int(input())

    a = list(map(int , input().split()))
    a.sort(reverse = True)

    m = int(input())

    min = 2147000000

    dfs(0,0)

    print(min)
