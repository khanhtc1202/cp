#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

#define MAX 100000

bool flag[MAX+1];
bool checked[MAX+1];
vector<int> graph[MAX+1];

int V, E;
bool checker;

void DFS(int s)
{
    flag[s] = true;
    checked[s] = true;
	for (int i = 0; i < graph[s].size(); i++)
	{
		if (flag[graph[s][i]])
		{
			checker = true;
			return;
		}
		if (checked[graph[s][i]])
		{
			continue;
		}
		DFS(graph[s][i]);
	}
	flag[s] = false;
}

void resetGraph()
{
    for (int i = 1; i <= V; i++)
    {
        graph[i].clear();
        flag[i] = false;
        checked[i] = false;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        resetGraph();

        cin >> V >> E;
        int u, v;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            graph[v].push_back(u);
        }

        checker = false;
        for (int i = 1; i <= V; i++)
        {
            if (!checked[i])
            {
				DFS(i);
                if (checker == true) break;
            }
        }
        if (checker) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
