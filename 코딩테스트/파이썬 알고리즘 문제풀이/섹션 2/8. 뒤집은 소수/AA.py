import sys
# sys.stdin = open("input.txt", "rt")
n = int(input())
arr = list(map(int , input().split()))


def reverse(x):
    # return int(str(x)[::-1])
    result =0

    while x>0:
        result = result*10 + x%10
        x = x//10
    return result


def isPrime(x):
    if x == 1 or x ==0 :
        return False
    for i in range (2, int(x**0.5+1)):
        if x % i  == 0 :
            return False
    return True
        

for i in arr:
    res = reverse(i)
    
    if isPrime(res) :
        print(res, end = ' ')





