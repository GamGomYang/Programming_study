import sys
import heapq

# 최대로 하려면 ? - 반대로 -씌우면 된다.

#sys.stdin = open("input.txt" , "rt")

heap = []
while True:

    s = int(input())

    if s == -1:
        break

    if s == 0:
        if len(heap) == 0:
            print(-1)
        print(-heapq.heappop(heap))

    else:
        heapq.heappush(heap, -s)