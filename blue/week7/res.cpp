#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

priority_queue<int, vector<int>, greater<int> > higher; // 1/3
priority_queue<int> lower;  // 2/3
vector<int> outs;

int main()
{
	int n;
	cin >> n;
	int c, v;
	int cnt = 0;
	while (n--)
	{
		cin >> c;
		switch (c)
		{
		case 1:
			cin >> v;
			cnt++;
			if (cnt%3 != 0)
			{
				if (higher.size() > 0 && v < higher.top())
				{
					lower.push(v);
				}
				else if (higher.size() > 0)
				{
					lower.push(higher.top());
					higher.pop();
					higher.push(v);
				}
				else
				{
					lower.push(v);
				}
			}
			else
			{
				if (v > lower.top())
				{
					higher.push(v);
				}
				else
				{
					higher.push(lower.top());
					lower.pop();
					lower.push(v);
				}
			}
			break;
		case 2:
			if (higher.size() == 0)
			{
				outs.push_back(0);
			}
			else
			{
				outs.push_back(higher.top());
			}
			break;
		default:
			break;
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
