#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
#include<numeric>
using namespace std;

priority_queue<int, vector<int>, greater<int> > hp;
vector<int> costs;
vector<int> outs;

int main()
{
	int n = 0;
	while(true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}

		int v;
		for (int i = 0; i < n; i++)
		{
			cin >> v;
			hp.push(v);
		}

		int sum = 0;
		int cost = 0;
		int s1, s2;
		while (hp.size() > 1)
		{
			s1 = hp.top();
			hp.pop();
			s2 = hp.top();
			hp.pop();
			sum = s1 + s2;
			hp.push(sum);
			cost += sum;
		}
		hp.pop();
		
		outs.push_back(cost);
	}

	for (int i = 0; i < outs.size(); i++)
	{
		cout << outs[i] << endl;
	}

	return 0;
}
