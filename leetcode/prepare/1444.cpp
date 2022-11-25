#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int mod = 1e9+7;
        int n = pizza.size(), m = pizza[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, 0)));
        
        vector<vector<int>> apples(n+1, vector<int>(m+1, 0));
        for (int i = n-1; i >= 0; i--)
            for (int j = m-1; j >= 0; j--)
                apples[i][j] = (pizza[i][j] == 'A') + apples[i+1][j] + apples[i][j+1] - apples[i+1][j+1];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[i][j][1] = apples[i][j] ? 1 : 0;
        
        for (int z = 2; z <= k; z++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    for (int x = i+1; x < n; x++) {
                        dp[i][j][z] += apples[i][j] - apples[x][j] ? dp[x][j][z-1] : 0;
                        dp[i][j][z] %= mod;
                    }
                    for (int y = j+1; y < m; y++) {
                        dp[i][j][z] += apples[i][j] - apples[i][y] ? dp[i][y][z-1] : 0;
                        dp[i][j][z] %= mod;
                    }
                }
        
        return dp[0][0][k];
    }
};
