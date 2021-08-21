#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v[100001];
int tim;
int ta[100001], td[100001];

void dfs(int x)
{
	tim++;
	ta[x] = tim;
	for (int i = 0; i < v[x].size(); ++i) {
		if (!ta[v[x][i]]) {
			dfs(v[x][i]);
			tim++;
		}
	}
	tim++;
	td[x] = tim;
}

int main()
{
	int n, q, a, b, c, x, y;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cin >> q;
	while (q--) {
		cin >> a >> b >> c;
		if (a == 1) swap(c, b);
		if (ta[b] <= ta[c] && td[c] <= td[b])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
