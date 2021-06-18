#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int p; int c;
	int cases = 1;
	while (true) {
		cin >> p >> c;
		if (p == 0 && c == 0)
		{
			break;
		}

		queue<int> q;
		int size = min(p, c);
		for (int i = 1; i <= size; i++) q.push(i);

		cout << "Case " << cases++ << ":" << endl;
		char exec;
		int k;
		for (int i = 0; i < c; i++)
		{
			cin >> exec;
			if (exec == 'N')
			{
				cout << q.front() << endl;
				q.push(q.front());
				q.pop();
			}
			else
			{
				cin >> k;
				q.push(k);
				int cnt = 0;
				while (cnt < size)
				{
					cnt++;
					q.push(q.front());
					q.pop();
				}
			}
		}
	}
	return 0;
}