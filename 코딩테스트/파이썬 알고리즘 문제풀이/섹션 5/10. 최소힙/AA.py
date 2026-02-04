import sys
import heapq

#sys.stdin = open("input.txt" , "rt")

heap = []
s = 0

while True:
    s = int(input())

    if s == -1:
        break

    if s == 0:
        if heap :
            print(heapq.heappop(heap))

        else :
            print(-1)
        
    else:
        #힙의 기본 자료 구조 -> heap.heappush(heap,s)
        #-> 리스트 + 숫자 2개의 arguments가 들어간다.
        heapq.heappush(heap,s)

