import sys
#sys.stdin = open("input.txt", "rt")

def dfs(l, sum, tsum):
    global result
    if sum + (total - tsum) < result:
        return
    if sum > weight:   
        return
    if l == n:
        result = max(result, sum)
        return

    dfs(l+1, sum + arr[l] , tsum + arr[l])  
    dfs(l+1, sum, tsum + arr[l])           


if __name__ == "__main__":
    weight, n = map(int, input().split())
    arr = []
    for _ in range(n):
        arr.append(int(input()))

    total = sum(arr)
    result = 0
    dfs(0, 0, 0)
    print(result)
