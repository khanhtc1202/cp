#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MAX 100000

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

const int INF = 1e9;

struct option
{
    bool operator() (const ii &a, const ii &b) const
    {
        return a.second > b.second;
    } 
};

vector<vii> graph;
// vi dist(MAX+1, INF);
// int path[MAX+1];

void dij(int s, vi& dist)
{
    priority_queue<ii, vii, option> heap;
    heap.push(ii(s, 0));
    dist[s] = 0;
    while (!heap.empty())
    {
        ii top = heap.top();
        heap.pop();
        int u = top.first;
        int w = top.second;
        if (dist[u] != w)
        {
            continue;
        }
        for (size_t i = 0; i < graph[u].size(); i++)
        {
            ii neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first])
            {
                dist[neighbor.first] = w + neighbor.second;
                heap.push(ii(neighbor.first, dist[neighbor.first]));
                // path[neighbor.first] = u;
            }
        }
    }
}


int main()
{
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    int c[k];
    for (size_t i = 0; i < k; i++)
        cin >> c[i];
    
    graph = vector<vii>(MAX+5, vii());
    vi dist_s(MAX+1, INF);
    vi dist_t(MAX+1, INF);

    int u, v, d;
    for (size_t i = 0; i < m; i++)
    {
        cin >> u >> v >> d;
        graph[u].push_back(ii(v, d));
        graph[v].push_back(ii(u, d));
    }

    int s, t; cin >> s >> t;
    dij(s, dist_s);
    dij(t, dist_t);

    vi pos;
    for (size_t i = 0; i < k; i++)
    {
        if (dist_t[c[i]] <= x)
            pos.push_back(c[i]);
    }

    if (pos.size() == 0)
        cout << -1 << endl;
    else
    {
        int shortest = INF;
        for (size_t i = 0; i < pos.size(); i++)
        {
            shortest = min(shortest, dist_t[pos[i]] + dist_s[pos[i]]);
        }
        cout << shortest << endl;
    }
	return 0;
}
