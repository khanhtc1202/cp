#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

#define MAX 10000
const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> dist(MAX+1, INF);
// int path[MAX+1];

struct option
{
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
	{
		return a.second > b.second;
	}
};

void Dijkstra(int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, option> pq;
	pq.push(make_pair(s, 0));
	dist[s] = 0;
	while (!pq.empty())
	{
		pair<int, int> top = pq.top();
		pq.pop();
		int u = top.first;
		int w = top.second;
		if (dist[u] != w)
		{
			continue;
		}
		for (int i = 0; i < graph[u].size(); i++)
		{
			pair<int, int> neighbor = graph[u][i];
			if (w + neighbor.second < dist[neighbor.first])
			{
				dist[neighbor.first] = w + neighbor.second;
				pq.push(pair<int, int>(neighbor.first, dist[neighbor.first]));
				// path[neighbor.first] = u;
			}
		}
	}
}

void resetDist()
{
    fill(dist.begin(), dist.end(), INF);
}

vector<int> output;
int main()
{
    int tests;
    cin >> tests;
    while (tests--)
    {
	    graph = vector<vector<pair<int, int> > >(MAX + 5, vector<pair<int, int> >());
        int n, m, k, s, t;
        cin >> n >> m >> k >> s >> t;

        int d, c, l;
        for (int i = 0; i < m; i++)
        {
            cin >> d >> c >> l;
            graph[d].push_back(pair<int, int>(c, l));
        }

        int u, v, q;
        int min_dist = INF;
        for (int i = 0; i < k; i++)
        {
            cin >> u >> v >> q;
            graph[u].push_back(pair<int, int>(v, q));
            graph[v].push_back(pair<int, int>(u, q));

            Dijkstra(s);
            min_dist = min(min_dist, dist[t]);

            graph[u].pop_back();
            graph[v].pop_back();
            resetDist();
        }


        if (min_dist == INF) output.push_back(-1);
        else output.push_back(min_dist);
    }
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
