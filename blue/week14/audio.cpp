#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
#include <cstring>
using namespace std;

#define MAX 100000
const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> dist(MAX, INF);
int path[MAX];
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
				path[v] = u;
			}
		}
	}
	
}

void getDist(vector<int>& c_dist)
{
    for (int i = 0; i < N; i++)
    {
        c_dist[i] = dist[i];
    }
    sort(c_dist.begin(), c_dist.end(), greater<int>());
}

void reset()
{
    for (int i = 0; i < N; i++)
    {
        graph[i].clear();
        visited[i] = false;
        dist[i] = INF;
        path[i] = -1;
    }
}

pair<int, int> maxCostByPath(int c1, int c2)
{
    int i = c2;
    int ans = dist[c2];
    if (c1 == c2) return make_pair(0, c1);
    while (1)
    {
        ans = max(ans, dist[i]);
        if (path[i] == -1) return make_pair(INF, i);
        i = path[i];
        if (i == c1) break;
    }
    return make_pair(ans, c1);
}

int maxCost(pair<int, int> p)
{
    pair<int, int> ans = maxCostByPath(p.first, p.second);
    if (ans.first != INF) return ans.first;
    // cout << "Get here in case: " << p.first << " -> " << p.second << endl;
    int r_to_c1 = maxCostByPath(ans.second, p.first).first;
    // cout << "1) " << p.first << " -> " << ans.second << " : " << r_to_c1 << endl;
    int r_to_c2 = maxCostByPath(ans.second, p.second).first;
    // cout << "2) " << p.second << " -> " << ans.second << " : " << r_to_c2 << endl;
    return max(r_to_c1, r_to_c2);
}

int all_visited()
{
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            s = i;
            return s;
        }
    }
    return -1;
}

int main()
{
    int Q;
    memset(path, -1, sizeof(path));
	graph = vector<vector<pair<int, int> > >(MAX + 5, vector<pair<int, int> >());
    int t_cnt = 1;
    while (cin >> N >> M >> Q, N != 0)
    {
        int c1, c2, d;
        for (int i = 0; i < M; i++)
        {
            cin >> c1 >> c2 >> d;
            graph[c1-1].push_back(make_pair(c2-1, d));
            graph[c2-1].push_back(make_pair(c1-1, d));
        }
        vector<pair<int, int> > qp;
        for (int i = 0; i < Q; i++)
        {
            cin >> c1 >> c2;
            qp.push_back(make_pair(c1-1, c2-1));
        }
        while (1)
        {
            int s = all_visited();
            if (s == -1) break;
            Prim(s);
        }
        // for(int i = 0; i < N; i++)
        // {
        //     cout << "Vertex: " << i << " | dist: " << dist[i] << " | path: " << path[i] << endl;
        // }
        if (t_cnt != 1) cout << endl;
        cout << "Case #" << t_cnt << endl;
        for (int i = 0; i < qp.size(); i++)
        {
            int ans = maxCost(qp[i]);
            // cout << qp[i].first << " -> " << qp[i].second << " : ";
            if (ans != INF) cout << ans << endl;
            else cout << "no path" << endl;
        }

        reset();
        t_cnt++;
    }
    

    return 0;
}