import queue
MAX = 10010
INF = int(1e9)
graph = [[] for z in range(MAX)]
dist = [INF for z in range(MAX)]
path = [-1 for z in range(MAX)]
class Node:
    def __init__(self, id, dist):
        self.dist = dist
        self.id = id
    def __lt__(self, other):
        return self.dist <= other.dist
def Dijkstra(s):
    pq = queue.PriorityQueue()
    pq.put(Node(s,0))
    dist[s] = 0
    while pq.empty()==False:
        top = pq.get()
        u = top.id
        w = top.dist
        if(dist[u]!=w):
            continue
        for neighbor in graph[u]:
            if w + neighbor.dist < dist[neighbor.id]:
                dist[neighbor.id] = w + neighbor.dist
                pq.put(Node(neighbor.id, dist[neighbor.id]))
                path[neighbor.id] = u

N = int(input())
E = int(input()) - 1
T = int(input())
M = int(input())

for i in range(M):
    u, v, w = map(int, input().split())
    u, v = u-1, v-1
    graph[v].append(Node(u, w))
Dijkstra(E)
count = 0
for i in range(N):
    if dist[i]<=T:
        count += 1
print(count)


