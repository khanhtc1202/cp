#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
#include <cstring>
using namespace std;

#define MAX 100000
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

void getDist(vector<int>& c_dist)
{
    for (int i = 0; i < N; i++)
    {
        c_dist[i] = dist[i];
    }
    sort(c_dist.begin(), c_dist.end(), greater<int>());
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
    int s = 0;
	Prim(s);
    
    int q;
    cin >> q;
    vector<int> c(q, 0);
    vector<int> d_dist(N, 0);
    for (int i = 0; i < q; i++)
    {
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    getDist(d_dist);
    int d_idx = 0, c_idx = 0;
    while (1)
    {
        if (d_dist[d_idx] <= c[c_idx]) break;
        if (d_idx == N || c_idx == N) break;
        d_dist[d_idx] = c[c_idx];
        d_idx++;
        c_idx++;
    }

    long ans = 0;
    for (int i = 0; i < N; i++)
        ans += d_dist[i];
    cout << ans << endl;
    

	return 0;
}
