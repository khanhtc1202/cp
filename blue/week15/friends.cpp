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
int num[MAX+5];
int N, M;

void makeSet()
{
	for (int i = 1; i <= MAX; i++)
	{
		parent[i] = i;
		ranks[i] = 0;
		num[i] = 1;
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
	if (ranks[up] > ranks[vp])
	{
		parent[vp] = up;
		num[up] += num[vp];
	}
	else if (ranks[up] < ranks[vp])
	{
		parent[up] = vp;
		num[vp] += num[up];
	}
	else
	{
		parent[up] = vp;
		num[vp] += num[up];
		ranks[vp]++;
	}
}

void reset()
{
	for (int i = 1; i <= N; i++)
	{
		ranks[i] = 0;
		num[i] = 1;
	}
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
		for (int i = 1; i <= N; i++)
		{
			cout << i << ": " << num[i] << endl;
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			if (parent[i] == i && num[i] > ans) ans = num[i];
		}
		cout << ans << endl;
		reset();
	}
	
	return 0;
}
