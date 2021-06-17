#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

struct task
{
	long long t, d, ts;
};

int main()
{
	int n, b;
	cin >> n >> b;

	task a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].t >> a[i].d;
		a[i].ts = 0;
	}

	queue<int> q;
	long long t = a[0].t + a[0].d;
	a[0].ts = t;
	q.push(t);
	for (int i = 1; i < n; i++)
	{
		while (q.size() > 0 && a[i].t >= q.front())
		{
			q.pop();
		}

		if (t <= a[i].t)
		{
			t = a[i].t + a[i].d;
			a[i].ts = t;
			q.push(t);
		}
		else
		{
			if (q.size() > b)
			{
				a[i].ts = -1;
			}
			else
			{
				t += a[i].d;
				a[i].ts = t;
				q.push(t);
			}
		}
	}

	for (int i = 0; i < n; i++) cout << a[i].ts << " ";

	return 0;
}