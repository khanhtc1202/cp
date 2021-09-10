#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
const int INF = 100000000;

vector<vector<ii> > dp;

ii knapsack(vector<ii>& items, int w)
{
    dp.assign(items.size() + 1, vector<ii>(w+1, ii(INF, 1)));
    for (int i = 1; i < items.size(); i++)
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j <= items[i].second)
                dp[i][j] = min(dp[i][j], ii(items[i].first, 1));
            else
                dp[i][j] = min(dp[i][j], ii(items[i].first + dp[i-1][max(0,j - items[i].first)].first, dp[i-1][max(0,j - items[i].first)].second+1));
        }
    return dp[items.size() - 1][w];
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int goal; cin >> goal;
        int n; cin >> n;
        vector<ii> items;
        items.push_back(ii(INF, INF));
        int c;
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            items.push_back(ii(c, c));
        }
        ii rans = knapsack(items, goal);
        cout << rans.first << " " << rans.second << endl;
    }
    
	return 0;
}
