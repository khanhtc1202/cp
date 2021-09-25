from queue import Queue
MAX = 100000 + 5
V = None
E = None
visited = [False for i in range(MAX)]
path = [-1 for i in range(MAX)]
graph = [[] for i in range(MAX)]
cats = [0 for i in range(MAX)]
leafs = []

def BFS(s, num_cats):
    for i in range(V):
        visited[i] = False
        path[i] = -1
    q = Queue()
    visited[s] = True
    q.put(s)
    if(have_cats[s]==1):
        cats[s] = 1
    while not q.empty():
        u = q.get()
        count = 0
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                q.put(v)
                path[v] = u
                count += 1
        if(count==0):
            leafs.append(u)

def printPath(s, f):
    b  = []
    if f == s:
        print(s)
        return
    if path[f] == -1:
        print("No Path")
        return
    while(True):
        b.append(have_cats[f])
        f = path[f]
        if f == s:
            b.append(have_cats[s])
            break
    # for i in range(len(b)-1, -1, -1):
        # print(b[i], end=' ')    
    return b

def consecutive(vertices):
    max_con = 0
    i = 0
    while(i<len(vertices)):
        if vertices[i]==1:
            count = 1
            i+=1
            while(i<len(vertices) and vertices[i]==1):
                count += 1
                i += 1
            if(count > max_con):
                max_con = count
        else:
            i+=1
    return max_con

V, num_cats = map(int, input().split())
have_cats = list(map(int, input().split()))
for i in range(V-1):
    u, v = map(int, input().split())
    u, v = u - 1, v - 1
    graph[u].append(v)
    graph[v].append(u)
s = 0
BFS(s, num_cats)
num_paths = 0
for leaf in leafs:
    b = printPath(s, leaf)
    if(consecutive(b)<=num_cats):
        num_paths += 1
print(num_paths)
