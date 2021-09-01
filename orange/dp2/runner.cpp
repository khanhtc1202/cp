#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;
#define MAX 2001
int dp[MAX][MAX];

int LCS(vector<int>& base, vector<int>& cmp, int m, int n)
{
	if (m == 0 || n == 0)
	{
		dp[m][n] = 0;
		return dp[m][n];
	}
	if (dp[m][n] != -1)
		return dp[m][n];
	else if (base[m-1] == cmp[n-1])
	{
		dp[m][n] = LCS(base, cmp, m-1, n-1) + 1;
		return dp[m][n];
	}
	else
	{
		dp[m][n] = max(LCS(base, cmp, m-1, n), LCS(base, cmp, m, n-1));
		return dp[m][n];
	}
}

int main()
{
	int d; cin >> d;
	while (d--)
	{
		string line;
		getline(cin, line);
		stringstream sin(line); int tmp;
		vector<int> base;
		while (sin >> tmp, tmp != 0)
		{
			base.push_back(tmp);
		}
		int ans = 0;

		vector<int> cmp;
		while (getline(cin, line), line != "0")
		{
			cmp.clear();
			stringstream sin(line); int tmp;
			while (sin >> tmp, tmp != 0)
			{
				cmp.push_back(tmp);
			}
			// LCS between each cmp with base.
			memset(dp, -1, sizeof(dp));
			ans = max(ans, LCS(base, cmp, base.size(), cmp.size()));
		}
		cout << ans << endl;
	}
	
	return 0;
}
