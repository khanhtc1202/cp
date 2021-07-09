#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MAX 105
#define INF 1e9

vector<vector<int> > graph;
vector<vector<int> > dist;
vector<vector<int> > path;
int V;

bool FloydWarshall(vector<vector<int> >& graph, vector<vector<int> >& dist)
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

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string line;
        cin >> line;
        V = line.length();
        graph = vector<vector<int> >(V, vector<int>(V));
        dist = vector<vector<int> >(V, vector<int>(V));
        path = vector<vector<int> >(V, vector<int>(V));
        for (int i = 0; i < V; i++)
        {
            if (line[i] == 'N' && i != 0)
                graph[0][i] = INF;
            else
                graph[0][i] = i == 0 ? 0 : 1;
        }
        for (int j = 1; j < V; j++)
        {
            cin >> line;
            for (int i = 0; i < V; i++)
            {
                if (line[i] == 'N' && i != j)
                    graph[j][i] = INF;
                else
                    graph[j][i] = i == j ? 0 : 1;
            }
        }

        FloydWarshall(graph, dist);
        int mf = 0, mi = 0;
        for (int i = 0; i < V; i++)
        {
            int cnt_f = 0;
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] == 2) cnt_f++;
            }
            if (cnt_f > mf)
            {
                mf = cnt_f;
                mi = i;
            }
        }
        cout << mi << " " << mf << endl;
    }
    
	return 0;
}
