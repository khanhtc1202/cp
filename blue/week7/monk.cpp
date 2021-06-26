#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

priority_queue<long long> hp;
vector<long long> out;

int main()
{
	int n;
	cin >> n;
	long long v1,v2,v3;
	while (n--)
	{
		int v;
		cin >> v;
		hp.push(v);
		if (hp.size() < 3)
		{
			out.push_back(-1);
		}
		else
		{
			v1 = hp.top();
			hp.pop();
			v2 = hp.top();
			hp.pop();
			v3 = hp.top();
			hp.pop();
			// push back
			hp.push(v1);
			hp.push(v2);
			hp.push(v3);
			out.push_back(v1*v2*v3);
		}
	}
	for (int i = 0; i < out.size(); i++)
	{
		cout << out[i] << endl;
	}

	return 0;
}
