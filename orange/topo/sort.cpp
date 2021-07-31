#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

int V, E;

bool Topo(vector<vector<int> >&graph, vector<int> &result)
{
	vector<int> indegree(V, 0);
	vector<int> zero_indegree; // Using priority_queue to get rid of using sort in each insert.
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
			zero_indegree.push_back(i);

	while (!zero_indegree.empty())
	{
		int u = zero_indegree.front();
		zero_indegree.erase(zero_indegree.begin());
		result.push_back(u);
		vector<int>::iterator it;
		for (it = graph[u].begin(); it != graph[u].end(); it++)
		{
			indegree[*it]--;
			if (indegree[*it] == 0)
				zero_indegree.push_back(*it);
		}
		sort(zero_indegree.begin(), zero_indegree.end());
	}
	for (int i = 0; i < V; i++)
		if (indegree[i] != 0)
			return false;
	return true;
}

int main()
{
	vector<vector<int> > graph;
	vector<int> result;
	cin >> V >> E;
	graph.assign(V, vector<int>());
	for (int u, v, i = 0; i < E; i++)
	{
		cin >> u >> v;
		graph[u-1].push_back(v-1);
	}
	if (!Topo(graph, result))
		cout << "Sandro fails." << endl;
	else
	{
		for (int i = 0; i < result.size(); i++)
			cout << result[i]+1 << " ";
		cout << endl;
	}
		
	return 0;
}
