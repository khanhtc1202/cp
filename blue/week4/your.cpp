#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	long long p; int c;
	int cases = 1;
	while (true) {
		cin >> p >> c;
		if (p == 0 && c == 0)
		{
			break;
		}

		vector<long long> q;
		stack<long long> pr_st;
		for (int i = 1; i <= p; i++) q.push_back(i);

		cout << "Case " << cases++ << ":" << endl;
		char exec;
		int k;
		for (int i = 0; i < c; i++)
		{
			cin >> exec;
			if (exec == 'N')
			{
				if (pr_st.empty())
				{
					cout << q.front() << endl;
					q.push_back(q.front());
					q.erase(q.begin());
				}
				else
				{
					cout << pr_st.top() << endl;
					q.push_back(pr_st.top());
					pr_st.pop();
				}
			}
			else
			{
				cin >> k;
				vector<long long>::iterator iter = find(q.begin(), q.end(), k);
				if (iter != q.end()) {
					q.erase(iter);
					pr_st.push(k);
				}
			}
		}
	}
	return 0;
}