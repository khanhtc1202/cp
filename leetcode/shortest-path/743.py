import queue
class Node:
    def __init__(self, id, dist):
        self.dist = dist
        self.id = id
    def __lt__(self, other):
        return self.dist <= other.dist
INF = int(1e9)

class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        def Dijkstra(s):
            dist = [INF for z in range(n)]
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
        graph = [[] for z in range(n)]
        for edge in edges:
            u, v, w = edge[0], edge[1], edge[2]
            graph[u].append(Node(v, w))
            graph[v].append(Node(u, w))
        counts = []
        for i in range(n):
            dist = Dijkstra(i)
            count = 0
            for j in range(n):
                if i!=j and dist[j] <= distanceThreshold:
                    count += 1
            counts.append((count, i))
        sorted_counts = sorted(counts, key=lambda x: (x[0], -x[1]))
        print(sorted_counts)
        return sorted_counts[0][1]
