#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
#include <cstring>
using namespace std;

#define MAX 10000
const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M; // vertex and edge

struct option
{
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
	{
		return a.second > b.second;
	}
};

void Prim(int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, option> pq;
	pq.push(make_pair(s, 0));
    dist[s] = 0;
	while (!pq.empty())
	{
		int u = pq.top().first;
		pq.pop();
		if (visited[u] == true) continue;
        visited[u] = true;
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if (!visited[v] && w < dist[v])
			{
				dist[v] = w;
				pq.push(make_pair(v, w));
				path[v] = u;
			}
		}
	}
	
}

long totalWeight()
{
    long ans = 0;
    for (int i = 0; i <= N; i++)
    {
        if (path[i] == -1) continue;
        ans += dist[i];
    }
    return ans;
}

void printGraph()
{
    for (int i = 0; i < N; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "<" << graph[i][j].first << ", " << graph[i][j].second << ">" << " | ";
        }
        cout << endl;
    }
}

int main()
{
	cin >> N >> M;
    memset(path, -1, sizeof(path));
	graph = vector<vector<pair<int, int> > >(MAX + 5, vector<pair<int, int> >());
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        graph[u-1].push_back(make_pair(v-1, w));
        graph[v-1].push_back(make_pair(u-1, w));
    }
    // printGraph();
    int s = 0;
	Prim(s);
	cout << totalWeight() << endl;
	return 0;
}
