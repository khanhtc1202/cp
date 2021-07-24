#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
#include <cstring>
#include <map>
#include <string>
using namespace std;

#define MAX 100
const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> dist(MAX, INF);
// int path[MAX];
bool visited[MAX];
int N, M; // vertex and edge

struct option
{
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
	{
		return a.second > b.second;
	}
};

void Prim(int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, option> pq;
	pq.push(make_pair(s, 0));
    dist[s] = 0;
	while (!pq.empty())
	{
		int u = pq.top().first;
		pq.pop();
		if (visited[u] == true) continue;
        visited[u] = true;
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if (!visited[v] && w < dist[v])
			{
				dist[v] = w;
				pq.push(make_pair(v, w));
				// path[v] = u;
			}
		}
	}
	
}

long totalWeight()
{
    long ans = 0;
    bool checker = true;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i]) checker = false;
        if (dist[i] == INF) return INF;
        ans += dist[i];
    }
    return checker ? ans : INF;
}

void resetGraph()
{
    for (int i = 0; i < N; i++)
    {
        graph[i].clear();
        visited[i] = false;
        dist[i] = INF;
    }
}

void print_s()
{
    for (int i = 0; i < N; i++)
    {
        // cout << cities[i] << " | ";
        cout << visited[i] << " | ";
        cout << dist[i] << " | ";
        cout << endl;
    }
}

int main()
{
    int T;
	cin >> T;
    int t_cnt = 1;
	graph = vector<vector<pair<int, int> > >(MAX + 5, vector<pair<int, int> >());
    // bool p = T == 5;
    while (T--)
    {
        string emp;
        getline(cin, emp);
        cin >> M;
        map<string, int> cities;
        string c1, c2;
        int w;
        int cnt = 0;
        // print_s();
        for (int i = 0; i < M; i++)
        {
            cin >> c1 >> c2 >> w;
            if (cities.find(c1) == cities.end())
            {
                cities[c1] = cnt;
                cnt++;
            }
            if (cities.find(c2) == cities.end())
            {
                cities[c2] = cnt;
                cnt++;
            }
            // if (p && t_cnt == 3) cout << c1 << " " << c2 << " " << w << endl;
            graph[cities[c1]].push_back(make_pair(cities[c2], w));
            graph[cities[c2]].push_back(make_pair(cities[c1], w));
        }
        N = cities.size();
        Prim(0);
        cout << "Case " << t_cnt << ": ";
        int cost = totalWeight();
        if (cost == INF) cout << "Impossible" << endl;
        else cout << cost << endl;
        t_cnt++;
        resetGraph();
    }
    
	return 0;
}
