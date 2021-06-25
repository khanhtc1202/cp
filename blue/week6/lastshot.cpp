#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

#define MAX 10000

bool visited[MAX+1];
vector<int> graph[MAX+1];
int path[MAX+1];
int dist[MAX+1];

int V, E;

void DFSRec(int s)
{
	visited[s] = true;
	for (int i = 0; i < graph[s].size(); i++)
	{
		int v = graph[s][i];
		if (!visited[v])
		{
			path[v] = s;
			DFSRec(v);
		}
	}
}

int DFS(int s)
{
    for (int i = 1; i <= V; i++)
    {
        visited[i] = false;
    }

    stack<int> st;
    visited[s] = true;
    st.push(s);

    // size of the bang
    int bang = 0;

    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        bang++;
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                st.push(v);
            }
        }
    }
    return bang;
}

int main()
{
    cin >> V >> E;

    int u, v;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int bigbang = 1;
    for (int i = 1; i <= V; i++)
    {
        bigbang = max(bigbang, DFS(i));
    }

    cout << bigbang << endl;

	return 0;
}
