#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
#include <map>
using namespace std;

#define MAX 30000
int parent[MAX+5];
int ranks[MAX+5];
int N, M;

void makeSet()
{
	for (int i = 1; i <= MAX; i++)
	{
		parent[i] = i;
		ranks[i] = 0;
	}
}

int findSet(int u)
{
	while (u != parent[u])
		parent[u] = findSet(parent[u]);
	return parent[u];
}

void unionSet(int u, int v)
{
	int up = findSet(u);
	int vp = findSet(v);
	if (up == vp) return;
	if (ranks[up] > ranks[vp]) parent[vp] = up;
	else if (ranks[up] < ranks[vp]) parent[up] = vp;
	else
	{
		parent[up] = vp;
		ranks[vp]++;
	}
}

void reset()
{
	for (int i = 1; i <= N; i++)
		ranks[i] = 0;
}

int main()
{
	int T;
	cin >> T;
	makeSet();
	while (T--)
	{
		cin >> N >> M;
		int a, b;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			unionSet(a, b);
		}
		map<int, int> rs;
		for (int i = 1; i <= N; i++)
		{
			map<int, int>::iterator it = rs.find(parent[i]);
			if (it == rs.end())
				rs[parent[i]] = 1;
			else rs[parent[i]]++;
		}
		map<int, int>::iterator rit;
		int ans = 0;
		for (rit = rs.begin(); rit != rs.end(); rit++)
		{
			ans = max(ans, rit->second);
		}
		cout << ans << endl;
		reset();
	}
	
	return 0;
}
