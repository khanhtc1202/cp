#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int* make_coin()
{
	static int coins[21];
	for (int i = 1; i <= 21; i++)
		coins[i-1] = i*i*i;
	return coins;
}

vector<ll> coinChangeProb(int total, int coins[], int n)
{
	vector<ll> dp(total+1);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j <= total; j++)
			dp[j] += dp[j - coins[i]];
	return dp;
}

int main()
{
	int* coins = make_coin();
	vector<ll> dp = coinChangeProb(9999, coins, 21);
	int n;
	vector<int> amount;
	while (cin >> n)
	{
		cout << dp[n] << endl;
	}
	
	return 0;
}
