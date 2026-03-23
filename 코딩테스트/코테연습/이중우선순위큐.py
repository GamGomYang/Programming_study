import heapq

def solution(operations):
    min_heap = []
    max_heap = []
    visited = {}
    idx = 0


    for op in operations :
        cmd , value = op.split()
        value = int(value)

        if cmd == 'I':
            heapq.heappush(min_heap , (value , idx))
            heapq.heappush(max_heap , (-value , idx))
            visited[idx] = True
            idx += 1

        elif cmd == 'D':
            if value == 1:
                while max_heap and not visited[max_heap[0][1]]:
                    heapq.heappop(max_heap)
                if max_heap :
                    _ , i = heapq.heappop(max_heap)
                    visited[i] = False

            if value == -1:
                while min_heap and not visited[min_heap[0][1]]:
                    heapq.heappop(min_heap)
                if min_heap:
                    _, i = heapq.heappop(min_heap)
                    visited[i] = False 

    while min_heap and not visited[min_heap[0][1]]:
        heapq.heappop(min_heap)
    while max_heap and not visited[max_heap[0][1]]:
        heapq.heappop(max_heap)
    if not min_heap or not max_heap:
        return [0, 0]    


    return [-max_heap[0][0], min_heap[0][0]]           
