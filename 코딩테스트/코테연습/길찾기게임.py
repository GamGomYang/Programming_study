from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)
def solution(nodeinfo):
    answer = [[]]
    nodes = []
    for idx, (x,y) in enumerate(nodeinfo):
        nodes.append((x,y,idx+1))

#lambda함수를 이용한 y내림차 , x 오름차순으로 정렬
    nodes.sort(key = lambda x : (-x[1],x[0]))
    
    class Node:
        def __init__(self, x,y,num):
            self.x = x
            self.y = y
            self.num =num
            self.left = None
            self.right = None
    
    def insert(parent , child):
        if child.x < parent.x:
            if parent.left is None:
                parent.left = child
            else:
                insert(parent.left , child)
        else:
            if parent.right is None:
                parent.right = child

            else:
                insert(parent.right , child)

    root = Node(*nodes[0])

    for x,y,num  in nodes[1:]:
        insert(root , Node(x,y,num))
    front = []
    last = []

    def dfs(node:Node):
        if node is None:
            return
        front.append(node.num)
        dfs(node.left)
        dfs(node.right)
        last.append(node.num)

    dfs(root)

    return [front, last]