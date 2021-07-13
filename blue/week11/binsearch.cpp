#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

int main()
{
	int n, q;
	int cnt = 0;
	while (cin >> n >> q, n + q != 0)
	{
		cnt++;
		vector<int> an(n);
		for (int i = 0; i < n; i++)
			cin >> an[i];
		
		sort(an.begin(), an.end());
		cout << "CASE# " << cnt << ":" << endl;
		int x;
		for (int i = 0; i < q; i++)
		{
			cin >> x;
			vector<int>::iterator lb = lower_bound(an.begin(), an.end(), x);
			int index = lb - an.begin();
			if ((index == 0 && an[0] != x) || (an[index] != x))
				cout << x << " not found" << endl;
			else
				cout << x << " found at " << index + 1 << endl;
		}
	}
	
	return 0;
}
