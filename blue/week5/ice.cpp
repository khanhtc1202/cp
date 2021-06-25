#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

#define MAX 1000
bool visited[MAX+1];
int V, E;
int path[MAX+1];
vector<int> graph[MAX+1];

void BFS(int s)
{
	// init
	for (int i = 1; i <= V; i++)
	{
		visited[i] = false;
		path[i] = -1;
	}
	// trigger
	queue<int> q;
	visited[s] = true;
	q.push(s);
	// Scan
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
				path[v] = u;
			}
		}
	}
}

void resetGraph()
{
	for (int i = 1; i <= V; i++)
	{
		graph[i].clear();
	}
}

int main()
{
	return 0;
}
