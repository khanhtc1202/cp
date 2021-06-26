#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

priority_queue<int> hp;
vector<int> outs;

int main()
{
	int n;
	cin >> n;
	int c, v;
	vector<int> tmp;
	while (n--)
	{
		cin >> c;
		if (c == 1)
		{
			cin >> v;
			hp.push(v);
		}
		else
		{
			int cnt = hp.size() / 3;
			if (cnt == 0)
			{
				outs.push_back(0);
				continue;
			}
			for (int i = 0; i < cnt; i++)
			{
				tmp.push_back(hp.top());
				hp.pop();
			}
			outs.push_back(tmp[tmp.size() - 1]);
			for (int i = 0; i < tmp.size(); i++)
			{
				hp.push(tmp[i]);
			}
			tmp.clear();
		}
	}
	for (int i = 0; i < outs.size(); i++)
	{
		if (outs[i] == 0)
		{
			cout << "No reviews yet" << endl;
		}
		else
		{
			cout << outs[i] << endl;
		}
	}
	
	return 0;
}
