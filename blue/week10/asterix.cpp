#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define INF 1e9

vector<vector<int> > graph;
vector<vector<int> > dist;
vector<vector<int> > path;
int V;

vector<vector<int> > cost;

bool FloydWarshall(vector<vector<int> >& graph, vector<vector<int> >& dist)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
			cost[i][j] = max(cost[i][i], cost[j][j]);
            // if (graph[i][j] != INF && i != j)
            // {
            //     path[i][j] = i;
            // }
            // else
            // {
            //     path[i][j] = -1;
            // }
        }
    }

	for (int p = 0; p < 2; ++p)
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < V; j++)
            {
                if (dist[k][j] != INF && dist[i][j] + cost[i][j] > dist[i][k] + dist[k][j] + max(cost[i][k], cost[k][j]))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // path[i][j] = path[k][j];
					cost[i][j] = max(cost[i][k], cost[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0)
            return false;

    return true;
}

void print_2x_mtx(vector<vector<int> >& X)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << X[i][j] << " | ";
        }
        cout << endl;
    }
}

vector<vector<int> > out;

int main()
{
	int r, q;
	int cnt = 0;
	
	while (true)
	{
		cin >> V >> r >> q;
		cnt++;
		if (V == 0) break;
		graph = vector<vector<int> >(V, vector<int>(V, INF));
        dist = vector<vector<int> >(V, vector<int>(V));
        cost = vector<vector<int> >(V, vector<int>(V, 0));
        // path = vector<vector<int> >(V, vector<int>(V, -1));
		for (int i = 0; i < V; i++)
		{
			cin >> cost[i][i];
		}
		int u, v, w;
		for (int i = 0; i < r; i++)
		{
			cin >> u >> v >> w;
			graph[u-1][v-1] = w;
			graph[v-1][u-1] = w;
		}
		for (int i = 0; i < V; i++)
		{
			graph[i][i] = 0;
		}
		vector<pair<int, int> > Q;
		int s, t;
		for (int i = 0; i < q; i++)
		{
			cin >> s >> t;
			Q.push_back(make_pair(s-1, t-1));
		}
		FloydWarshall(graph, dist);
		// print_2x_mtx(cost);
		// cout << "================" << endl;
		// print_2x_mtx(dist);
		// cout << "Case #" << cnt << endl;
		for (int i = 0; i < Q.size(); i++)
		{
			if (dist[Q[i].first][Q[i].second] == INF) out[cnt].push_back(-1);
			// else cout << dist[Q[i].first][Q[i].second] + cost[Q[i].first][Q[i].second] << endl;
			else out[cnt].push_back(dist[Q[i].first][Q[i].second] + cost[Q[i].first][Q[i].second]);
		}
		// cout << endl;
	}
	for (int i = 0; i < out.size(); i++)
	{
		if (out[i].size() == 0) continue;
		for (int j = 0; j < out[i].size(); j++)
			cout << out[i][j] << endl;
		if (i != out.size()-1) cout << endl;
	}
	
	return 0;
}
