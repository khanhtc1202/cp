#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n <= 0) {
			break;
		}

		int cars[n];
		for (int i = 0; i < n; i++)
		{
			cin >> cars[i];
		}

		stack<int> sub;
		int k = 0, i = 0;
		while (i < n)
		{
			while (!sub.empty() && sub.top() == k+1)
			{
				sub.pop();
				k++;
			}
			if (cars[i] != k+1)
			{
				sub.push(cars[i]);
			} 
			else
			{
				k++;
			}
			i++;
		}
		while (!sub.empty() && sub.top() == k+1)
		{
			sub.pop();
			k++;
		}
		if (k == n) cout << "yes" << endl;
		cout << "no" << endl;
	}
	
	return 0;
}