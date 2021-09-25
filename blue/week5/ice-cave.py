'''
4 6
X...X.
...XX.
.X..X.
......
1 6
2 2
'''

from queue import Queue
MAX = 500*500
E = None
visited = [False for i in range(MAX)]
path = [0 for i in range(MAX)]
graph = [[] for i in range(MAX)]

def BFS(s, dest, dest_type):
    for i in range(len(graph)):
        visited[i]=False
        path[i]=-1
    q = Queue()
    visited[s]=True
    q.put(s)
    while not q.empty():
        u = q.get()
        # print('************', u, graph[u])
        if(u==dest):
            if(dest_type=='X'):
                return True
            else:
                if(len(graph[u])>1):
                    return True
                return False            
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                q.put(v)
                path[v]=u
    return False


inputs = list(map(int, input().split()))
n, m = inputs[0], inputs[1]
strings = []
graph = [[] for i in range(n*m)]
for i in range(n):
    strings.append(input())
vertex_1 = list(map(int, input().split()))
vertex_2 = list(map(int, input().split()))
for i in range(n):
    for j in range(m):
        c = strings[i][j]
        if(i==vertex_1[0]-1 and j==vertex_1[1]-1):
            c = 'X'
        if(c=='.' or (i==vertex_1[0]-1 and j==vertex_1[1]-1) or (i==vertex_2[0]-1 and j==vertex_2[1]-1)):
            if(i>0):
                if(strings[i-1][j]=="."):
                    graph[i*m+j].append((i-1)*m+j)
                if (i==vertex_1[0]-1 and j==vertex_1[1]-1) or (i==vertex_2[0]-1 and j==vertex_2[1]-1):
                    graph[(i-1)*m+j].append(i*m+j)
            if(i<n-1):
                if(strings[i+1][j]=="."):
                    graph[i*m+j]+=[((i+1)*m+j)]
                if (i==vertex_1[0]-1 and j==vertex_1[1]-1) or (i==vertex_2[0]-1 and j==vertex_2[1]-1):
                    graph[((i+1)*m+j)].append(i*m+j)
            if(j>0):
                if(strings[i][j-1]=="."):
                    graph[i*m+j].append(i*m+j-1)
                if (i==vertex_1[0]-1 and j==vertex_1[1]-1) or (i==vertex_2[0]-1 and j==vertex_2[1]-1):
                    graph[i*m+j-1].append(i*m+j)
            if(j<m-1):
                if(strings[i][j+1]=="."):
                    graph[i*m+j].append(i*m+j+1)
                if (i==vertex_1[0]-1 and j==vertex_1[1]-1) or (i==vertex_2[0]-1 and j==vertex_2[1]-1):
                    graph[i*m+j+1].append(i*m+j)

# for i in range(len(graph)):
    # print("vertex", i, graph[i])        

source = (vertex_1[0]-1)*m+(vertex_1[1]-1)
dest = (vertex_2[0]-1)*m+(vertex_2[1]-1)
dest_type = strings[vertex_2[0]-1][vertex_2[1]-1]
# print(source, dest, dest_type)
# print(graph[5])
# if(n==109 and m==260):
#     print("Yes")
#     print(vertex_1, strings[vertex_1[0]-1][vertex_1[1]-1])
#     print(vertex_2, dest_type)
#     exit()
if(BFS(source, dest, dest_type)):
    print("Yes")
else:
    print("No")        
