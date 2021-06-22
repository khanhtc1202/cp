#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

#define MAX 1000

bool visited[MAX+1];
vector<int> graph[MAX+1];
int path[MAX+1];
int dist[MAX+1];

int n;

void DFS(int s)
{
	visited[s] = true;
	for (int i = 0; i < graph[s].size(); i++)
	{
		int v = graph[s][i];
		if (!visited[v])
		{
			path[v] = s;
			DFS(v);
		}
	}
}

void BFS(int s)
{
	// init
	for (int i = 1; i <= n; i++)
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

int main()
{
	cin >> n;

	int u, v;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int q;
	cin >> q;
	queue<int> cities;
	int c;
	for (int i = 0; i < q; i++)
	{
		cin >> c;
		cities.push(c);
	}

	BFS(1);
	vector<pair<int, int> > rs;
	while (!cities.empty())
	{
		rs.push_back(pair<int, int> (dist[cities.front()], cities.front()));
		cities.pop();
	}

	sort(rs.begin(), rs.end());
	cout << rs[0].second << endl;
	

	return 0;
}
