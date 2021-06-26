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
	int n;
	do
	{
		cin >> n;

		int v;
		for (int i = 0; i < n; i++)
		{
			cin >> v;
			hp.push(v);
		}

		int v0 = hp.top();
		hp.pop();
		int v1 = hp.top();
		hp.pop();
		costs.push_back(v0+v1);
		while(!hp.empty())
		{
			int last = costs[costs.size() - 1];
			costs.push_back(last + hp.top());
			hp.pop();
		}

		int sum = 0;
		for (int i = 0; i < costs.size(); i++)
		{
			sum += costs[i];
		}
		outs.push_back(sum);
		
	} while (n != 0);

	for (int i = 0; i < outs.size(); i++)
	{
		cout << outs[i] << endl;
	}
	return 0;
}
