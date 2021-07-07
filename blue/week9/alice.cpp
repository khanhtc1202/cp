#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

#define MAX 2005
const long INF = 2e30;

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
    void print()
    {
        cout << this->source << " | " << this->target << " | " << this-> weight << endl;
    }
};

vector<long> dist(MAX, INF);
// vector<int> path(MAX, -1);
vector<Edge> graph;

bool BellmanFord(int s, int n, int m)
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
				// path[v] = u;
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

void resetDist(int n)
{
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
	}
}

void resetGraph()
{
    graph.clear();
}

void printGraph()
{
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i].print();
    }
}

int main()
{
    int n;
    int cnt = 0;
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        cnt++;

        unordered_map<int, string> um;
        string name;
        int w;
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> name;
            um.insert(pair<int, string>(i, name));
            for (int j = 0; j < n; j++)
            {
                cin >> w;
                if (w == 0) continue;
                graph.push_back(Edge(i, j, w));
                m++;
            }
        }
        int q;
        cin >> q;
        vector<pair<int, int> > Q1; // [(1,1), (0,1)]
        int u, v;
        for (int i = 0; i < q; i++)
        {
            cin >> u >> v;
            Q1.push_back(make_pair(u, v));
        }

        cout << "Case #" << cnt << ":" << endl;
        // printGraph();

        for (int i = 0; i < Q1.size(); i++)
        {
            pair<int, int> c = Q1[i];
            if (!BellmanFord(c.first, n, m))
            {
                cout << "NEGATIVE CYCLE" << endl;
            }
            else
            {
                if (dist[c.second] == INF)
                {
                    cout << um.at(c.first) << "-" << um.at(c.second) << " NOT REACHABLE" << endl;
                }
                else
                {
                    cout << um.at(c.first) << "-" << um.at(c.second) << " " << dist[c.second] << endl;
                }
            }
            resetDist(n);
        }

        resetGraph();
    }
    
	return 0;
}
