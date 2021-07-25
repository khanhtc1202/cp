import queue
class Node:
    def __init__(self, id, dist):
        self.dist = dist
        self.id = id
    def __lt__(self, other):
        return self.dist <= other.dist

def lenMST():
    ans = 0
    for i in range(n):
        if path[i] == -1:
            continue
        ans+=dist[i]
    return ans

def prims(src):
    pq = queue.PriorityQueue()
    pq.put(Node(src, 0))
    dist[src] = 0
    while pq.empty() == False:
        top = pq.get()
        u  = top.id
        visited[u] = True
        for neighbor in graph[u]:
            v = neighbor.id
            w = neighbor.dist
            if visited[v] == False and w < dist[v]:
                dist[v] = w
                pq.put(Node(v, w))
                path[v] = u

INF = 1e9
num_tests = int(input())
results = []
for i in range(num_tests):
    p = int(input())
    n = int(input())
    m = int(input())
    graph = [[] for i in range(n)]
    dist = [INF for i in range(n)]
    path = [-1 for i in range(n)]
    visited = [False for i in range(n)]
    for i in range(m):
        u, v, w = map(int, input().split())
        graph[u-1].append(Node(v-1, w))
        graph[v-1].append(Node(u-1, w))
    prims(0)
    lenroad = lenMST()
    price = lenroad*p
    results.append(price)
for result in results:
    print(result)
