import sys
#sys.stdin = open("input.txt", "rt")

def dfs(level):
    global cnt
    if level == m:
        for j in range(m):
            print(res[j] , end = ' ')
        print()
        cnt+=1
    else:
        for i in range(1, n+1):
            res[level] = i
            dfs(level+1)

if __name__ == "__main__":
    n, m = map(int, input().split())
    res = [0] * m
    cnt = 0

    dfs(0)
    print(cnt)
