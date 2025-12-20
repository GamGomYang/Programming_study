import sys
# sys.stdin = open("input.txt" , "rt")

n = int(input())
isPrime = [True]*(n+1)
isPrime[0] = False
isPrime[1] = False

for i in range(2, int(n**0.5)+1):
    if isPrime[i]:
        for j in range(i*i, n+1, i ):
            isPrime[j] = False

primes = []
cnt = 0
for i in range(2, n+1):
    if isPrime[i]:
       cnt+=1 

print(cnt)



