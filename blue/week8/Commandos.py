import queue
MAX = 10010
INF = int(1e9)

class Node:
    def __init__(self, id, dist):
        self.dist = dist
        self.id = id
    def __lt__(self, other):
        return self.dist <= other.dist
def Dijkstra(s):
    dist = [INF for z in range(MAX)]
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
    return dist

T = int(input())

results = []
for i in range(T):
    graph = [[] for z in range(MAX)]
    N = int(input())
    R = int(input())
    for i in range(R):
        u, v = map(int, input().split())
        graph[u].append(Node(v, 1))
        graph[v].append(Node(u, 1))
    s, d = map(int, input().split())
    dist_s = Dijkstra(s)
    dist_d = Dijkstra(d)
    max_dist = 0
    for i in range(N):
        distance = dist_s[i] + dist_d[i]
        if distance > max_dist:
            max_dist = distance
    results.append(max_dist)
for i, result in enumerate(results):
    print("Case "+str(i+1)+": "+str(result))

