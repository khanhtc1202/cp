#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

priority_queue<int, vector<int>, greater<int> > hp;
vector<int> outs;

int main()
{
	int q;
	cin >> q;
	int c, v;
	vector<int> tmp;
	while (q--)
	{
		cin >> c;
		switch (c)
		{
		case 1:
			cin >> v;
			hp.push(v);
			break;
		case 2:
			cin >> v;
			while (hp.top() != v)
			{
				tmp.push_back(hp.top());
				hp.pop();
			}
			hp.pop();
			for (int i = 0; i < tmp.size(); i++)
			{
				hp.push(tmp[i]);
			}
			tmp.clear();
			break;
		case 3:
			outs.push_back(hp.top());
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < outs.size(); i++)
	{
		cout << outs[i] << endl;
	}
	
	return 0;
}
