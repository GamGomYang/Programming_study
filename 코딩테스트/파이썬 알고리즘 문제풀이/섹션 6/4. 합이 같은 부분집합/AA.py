import sys
#sys.stdin = open("input.txt" , "rt")

def dfs(l , sum):
    if sum > total // 2:
        return
    if l == n:
        if sum == (total - sum):
            print("YES")
            sys.exit(0)
    else:
        dfs(l+1 , sum + a[l])
        dfs(l+1, sum) 

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))

    total = sum(a) 
    dfs(0,0)
    print("NO")

# import sys
# sys.stdin = open("input.txt", "rt")
# def dfs(v, sum1, sum2):
#     if v == n:
#         return sum1 == sum2
#     if dfs(v+1, sum1 + arr[v], sum2):
#         return True
#     if dfs(v+1, sum1, sum2 + arr[v]):
#         return True
#     return False

# if __name__ == "__main__":
#     status = False
#     n = int(input())
#     arr = list(map(int , input().split()))

#     if dfs(0, 0, 0 ):
#         status = True
#     if status :
#         print("YES")
#     else:
#         print("NO")
