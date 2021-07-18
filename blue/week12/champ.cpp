#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define MAX 1000
bool visited[MAX+1];
int V, E;
int dist[MAX+1];
vector<int> graph[MAX+1];

void BFS(int s)
{
	// init
	for (int i = 1; i <= V; i++)
	{
		visited[i] = false;
		dist[i] = 0;
	}
	// trigger
	queue<int> q;
	visited[s] = true;
	q.push(s);
	// Scan
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
}

int main()
{
    int n;
    cin >> n;
    map<string, int> mn;
    int idx = 0;
    while (n--)
    {
        string name[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> name[i];
            if (mn.find(name[i]) == mn.end())
            {
                mn[name[i]] = idx;
                idx++;
            }
        }
        graph[mn[name[0]]].push_back(mn[name[1]]);
        graph[mn[name[1]]].push_back(mn[name[0]]);
        graph[mn[name[0]]].push_back(mn[name[2]]);
        graph[mn[name[2]]].push_back(mn[name[0]]);
        graph[mn[name[2]]].push_back(mn[name[1]]);
        graph[mn[name[1]]].push_back(mn[name[2]]);
    }
    BFS(mn["Isenbaev"]);
    map<string, int>::iterator it;
    for (it = mn.begin(); it != mn.end(); it++)
    {
        int dis;
        if (dist[it->second] == 0 && it->first != "Isenbaev")
            cout << it->first << " undefined" << endl;
        else
            cout << it->first << " " << dist[it->second] << endl;
    }
    
    return 0;
}