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
		int n, m;
		cin >> n >> m;
		set<double> s;
		double tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			s.insert(tmp);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> tmp;
			int bf = s.size();
			s.insert(tmp);
			if (s.size() == bf) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	
	return 0;
}
