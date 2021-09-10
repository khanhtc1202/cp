#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

vector<vector<int> > dp;

int knapsack(vector<ii>& items, int w)
{
    dp.assign(items.size() + 1, vector<int>(w+1, 0));
    for (int i = 1; i < items.size(); i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (items[i].second > j)
                dp[i][j] = dp[i-1][j];
            else
            {
                int tmp1 = items[i].first + dp[i-1][j - items[i].second];
                int tmp2 = dp[i-1][j];
                dp[i][j] = max(tmp1, tmp2);
            }
        }
    }
    return dp[items.size() - 1][w];
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int sum = 0, c;
        vector<ii> items;
        items.push_back(ii(0,0));
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            sum += c;
            items.push_back(ii(c, c));
        }
        int w = sum / 2;
        cout << sum - 2*knapsack(items, w) << endl;
    }
    
	return 0;
}
