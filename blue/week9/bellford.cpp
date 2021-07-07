#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

#define MAX 2005
const int INF = 1e9;

struct Edge
{
	int source;
	int target;
	int weight;
	Edge(int source = 0, int target = 0, int weight = 0)
	{
		this->source = source;
		this->target = target;
		this->weight = weight;
	}
};

vector<int> dist(MAX, INF);
vector<int> path(MAX, -1);
vector<Edge> graph;
int n, m;

bool BellmanFord(int s)
{
	int u, v, w;
	dist[s] = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		bool stoppable = true;
		for (int j = 0; j < m; j++)
		{
			u = graph[j].source;
			v = graph[j].target;
			w = graph[j].weight;
			if (dist[u] != INF && (dist[u] + w < dist[v]))
			{
				dist[v] = dist[u] + w;
				path[v] = u;
				stoppable = false;
			}
		}
		if (stoppable) break;
	}
	for (int i = 0; i < m; i++)
	{
		u = graph[i].source;
		v = graph[i].target;
		w = graph[i].weight;
		if (dist[u] != INF && (dist[u] + w < dist[v]))
			return false;
	}
	return true;
}

void reset()
{
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		path[i] = -1;
	}
	graph.clear();
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int s,u,v,w;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			graph.push_back(Edge(u,v,w));
		}
		s = graph[0].source;
		if (BellmanFord(s)) cout << "not possible" << endl;
		else cout << "possible" << endl;

		reset();
	}
	return 0;
}
