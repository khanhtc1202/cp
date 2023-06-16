/*
https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        vector<vector<long long>> table;
        long long mod = 1e9+7;

        int n = nums.size();
        table.resize(n+1);
        for (int i = 0; i <= n; i++) {
            table[i] = vector<long long>(i+1, 1);
            for (int j = 1; j < i; j++) {
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }

        function<long long(vector<int>&)> dfs = [&](vector<int> bucket) -> long long {
            int m = bucket.size();
            if (m < 3) return 1;

            vector<int> left, right;
            for (int i = 1; i < m; i++) {
                if (bucket[i] < bucket[0])
                    left.push_back(bucket[i]);
                else
                    right.push_back(bucket[i]);
            }

            long long leftWays = dfs(left) % mod;
            long long rightWays = dfs(right) % mod;

            return (((leftWays * rightWays) % mod) * table[m-1][left.size()]) % mod;
        };

        return (dfs(nums) - 1) % mod;
    }
};
