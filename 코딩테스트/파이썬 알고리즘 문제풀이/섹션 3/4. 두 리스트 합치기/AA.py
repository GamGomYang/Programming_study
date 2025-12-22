import sys
# sys.stdin = open("input.txt", "rt")
n = int(input())
n_arr = list(map(int, input().split()))
m = int(input())
m_arr = list(map(int, input().split()))
# new_arr = n_arr + m_arr
# new_arr.sort()
# for i in range(n+m):
#     print(new_arr[i], end = ' ')

p1=p2=0
c = []
while p1<n and p2<m:
    if n_arr[p1]<=m_arr[p2]:
        c.append(n_arr[p1])
        p1+=1
    else:
        c.append(m_arr[p2])
        p2+=1
if p1<n:
    c = c+n_arr[p1:]
if p2<m:
    c = c+m_arr[p2:]

for i in range(n+m):
    print(c[i], end = ' ')

