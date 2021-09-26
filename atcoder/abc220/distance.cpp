#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;
#define LL long long

#define INF 1e9

vector<vector<int> > graph;
vector<vector<LL> > dist;
vector<vector<int> > path;
int V;

void FloydWarshall(vector<vector<int> >& graph, vector<vector<LL> >& dist)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j)
            {
                path[i][j] = i;
            }
            else
            {
                path[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < V; j++)
            {
                if (dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    return;
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

int main()
{
    cin >> V;
    graph = vector<vector<int> >(V, vector<int>(V, INF));
    dist = vector<vector<LL> >(V, vector<LL>(V));
    path = vector<vector<int> >(V, vector<int>(V));
    for (int i = 0; i < V; i++)
    {
        graph[i][i] = 0;
    }
    string line;
    int u, v;
    while (getline(cin, line))
    {
        stringstream sin(line);  
        sin >> u >> v;
        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1;
    }
    
    FloydWarshall(graph, dist);
    LL out;
    for (int i = 0; i < V; i++)
    {
        out = 0;
        for (int j = 0; j < V; j++)
            out += dist[i][j];
        cout << out << endl;
    }
}
