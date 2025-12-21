import sys
# sys.stdin = open("input.txt","rt")


s = str(input())

res = ""

for i in s:
    if i>='A' and i<='z' :
        continue
    else:
        res += i
    

result = int(res)

cnt = 0
for i in range(1,result+1):
    if(result % i == 0):
        cnt +=1


print(result)
print(cnt)




