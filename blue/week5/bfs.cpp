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
int dist[MAX+1];
vector<int> graph[MAX+1];

void BFS(int s)
{
	// init
	for (int i = 1; i <= V; i++)
	{
		visited[i] = false;
		dist[i] = 0;
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
				dist[v] = dist[u] + 1;
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
	int q;
	cin >> q;
	while (q--)
	{
		int u, v;
		cin >> V >> E;
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int s;
		cin >> s;
		BFS(s);
		for (int i = 1; i <= V; i++)
		{
			if (i == s)
				continue;
			if (dist[i] != 0)
				cout << dist[i] * 6 << " ";
			else
				cout << -1 << " ";
		}
		cout << endl;
		resetGraph();
	}
	return 0;
}
