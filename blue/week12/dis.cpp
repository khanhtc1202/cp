#include <iostream>
#include <algorithm>
#include <set>
#include <limits>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, x;
		cin >> n >> x;
		set<int> s;
		int tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			s.insert(tmp);
		}
		if (s.size() == x) cout << "Good" << endl;
		else if (s.size() > x) cout << "Average" << endl;
		else cout << "Bad" << endl;
	}
	
	return 0;
}
