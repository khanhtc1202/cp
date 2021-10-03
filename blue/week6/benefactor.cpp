#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
#include <cstring>
using namespace std;

#define ii pair<int, int>
#define MAX 50005

vector<ii> graph[MAX+1];
int dist[MAX+1];
int max_dist = 0;
int leaf;

void DFS(int s)
{
	for (int i = 0; i < graph[s].size(); i++)
	{
		ii v = graph[s][i];
		if (dist[v.first] == -1)
		{
			dist[v.first] = dist[s] + v.second;
            if (dist[v.first] > max_dist)
            {
                max_dist = dist[v.first];
                leaf = v.first;
            }
			DFS(v.first);
		}
	}
}

int main()
{
    int t; cin >> t;
    int V;
    while (t--)
    {
        cin >> V;

        for (size_t i = 0; i <= V; i++)
        {
            graph[i].clear();
        }

        int u,v,d;
        for (size_t i = 0; i < V-1; i++)
        {
            cin >> u >> v >> d;
            graph[u].push_back(ii(v,d));
            graph[v].push_back(ii(u,d));
        }

        max_dist = 0;

        memset(dist, -1, sizeof(dist));
        dist[1] = 0; // reset dist for starting point.
        DFS(1);
        // for (size_t i = 1; i <= V; i++)
        //     if (dist[i] > max_dist)
        //     {
        //         max_dist = dist[i];
        //         leaf = i;
        //     }

        memset(dist, -1, sizeof(dist));
        dist[leaf] = 0; // reset dist for starting point.
        DFS(leaf);
        // for (size_t i = 1; i <= V; i++)
        //     if (dist[i] > max_dist)
        //         max_dist = dist[i];
        
        cout << max_dist << endl;
    }
    
    return 0;
}
