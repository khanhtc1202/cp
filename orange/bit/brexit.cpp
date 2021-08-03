#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

int V;

void Topo(vector<vector<int> >& graph, vector<int>& cost)
{
    vector<int> indegree(V, 0);
    priority_queue<pi> zero_heap;
    for (int u = 0; u < V; u++)
    {
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]++;
        }
    }
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            zero_heap.push(pi(cost[i], i));

    int done = 0;
    while (!zero_heap.empty())
    {
        int u = zero_heap.top().second;
        zero_heap.pop();
        cost[u] += done;
        done++;
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
                zero_heap.push(pi(cost[*it], *it));
        }
    }
}

int main()
{
    vector<vector<int> > graph;

    cin >> V;
    vector<int> cost(V, 0);
    graph.assign(V, vector<int>());

    for (int c, e, i = 0; i < V; i++)
    {
        cin >> c >> e;
        cost[i] = c;
        for (int nebor, j = 0; j < e; j++)
        {
            cin >> nebor;
            graph[nebor-1].push_back(i);
        }
    }

    Topo(graph, cost);
    cout << *max_element(cost.begin(), cost.end()) << endl;
	return 0;
}
