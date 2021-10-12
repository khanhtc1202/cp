#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MAX 20000

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
vi dist(MAX+1, INF);
int path[MAX+1];

void dij(int s)
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
                path[neighbor.first] = u;
            }
        }
    }
}

int main()
{
    int q; cin >> q;
    int cnt = 0;
    while (q--)
    {
        graph = vector<vii>(MAX+1, vii());
        fill(dist.begin(), dist.end(), INF);

        int n, m, s, t;
        cin >> n >> m >> s >> t;

        int u, v, w;
        for (size_t i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            graph[u].push_back(ii(v, w));
            graph[v].push_back(ii(u, w));
        }
        dij(s);
        cout << "Case #" << ++cnt << ": ";
        if (dist[t] == INF)
            cout << "unreachable" << endl;
        else
            cout << dist[t] << endl;
    }
    
	return 0;
}
