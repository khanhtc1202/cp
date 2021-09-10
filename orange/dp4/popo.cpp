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

void printDP(vector<vector<int> >& dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

void printV(vector<ii> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "(" << v[i].first << "," << v[i].second << ")" << " ";
    }
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int x, y, z;
        vector<ii> items;
        items.push_back(ii(0,0));
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            items.push_back(ii(x*y, z));
        }
        cout << knapsack(items, w) << endl;
        // printV(items);
        // printDP(dp);
    }
    
	return 0;
}
