import sys
sys.stdin = open("input.txt" , "rt")
def dfs(L):
    global cnt 
    if L == m :
        for j in range(L):
            print(res[j] , end = ' ')
        print()
        cnt +=1
    else:
        for i in range(1 , n+1):
            # 순열은 체크 ch방법으로 구현함
            if ch[i] == 0:
                ch[i] = 1
                res[L] = i
                dfs(L+1)
                ch[i] = 0
    

if __name__ == "__main__":
    n, m = map(int,input().split())
    cnt = 0
    ch = [0]*(n+1)
    res = [0] * (m+1)
    dfs(0)
    print(cnt)

