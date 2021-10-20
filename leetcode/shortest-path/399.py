from queue import Queue

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = collections.defaultdict(dict)
        for (x, y), value in zip(equations, values):
            graph[x][y] = value
            graph[y][x] = 1/value
        print(graph)
        visited = set()
        def dfs(x, y, visited):
            if x not in graph or y not in graph:
                return -1
            if y in graph[x]:
                return graph[x][y]
            for i in graph[x]:
                if i not in visited:
                    visited.add(i)
                    temp = dfs(i, y, visited)
                    if temp == -1:
                        continue
                    else:
                        return graph[x][i]*temp
            return -1
        results = []
        for query in queries:
            results.append(dfs(query[0], query[1], set()))
        return results
