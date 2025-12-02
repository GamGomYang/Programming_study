from heapq import heappush , heappop

def manhattan(a, b):
    return abs(a[0] - b[0]) + abs(a[1]- b[1])

def astar(grid, start, goal):

    rows , cols = len(grid), len(grid[0])
    open_set = []
    heappush(open_set , (0 , start))
    came_from = {}
    g = {start : 0}

    while open_set:
        _, current = heappop(open_set)

        if current == goal :
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path [::-1]
        

        x, y = current
        for dx, dy in [(1,0),(0,1),(-1,0),(0,-1)]:
            nx , ny = x+dx , y+dy
            next_node = (nx, ny)

            # 좌표 범위 밖 및 장애물 만나면 스킵
            if not(0 <= nx <rows and 0 <= ny <cols):
             continue
            if grid[nx][ny] == 1 :
             continue       
        
            new_cost = g[current]+1

            if next_node not in g or new_cost < g[next_node]:
                g[next_node] = new_cost
                priority = new_cost + manhattan(goal , next_node)
                heappush(open_set, (priority, next_node))
                came_from[next_node] = current



grid = [
    [0,0,0,0,0],
    [1,1,0,1,0],
    [0,0,0,1,0],
    [0,1,0,0,0],
    [0,0,0,1,0]
]

start = (0,0)
goal = (4,4)

path = astar(grid, start, goal)
print("경로:", path)