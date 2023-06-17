/*
https://leetcode.com/problems/make-array-strictly-increasing/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());

        map<pair<int,int>, int> memo;
        function<int(int, int)> dfs = [&](int i, int prev) -> int {
            if (i == arr1.size()) return 0;

            if (memo.find(make_pair(i, prev)) != memo.end()) {
                return memo[make_pair(i, prev)];
            }

            int cost = 2001;

            // If the arr1[i] greater the prev, then can let it be (no change).
            if (arr1[i] > prev) {
                // mean we call the dfs with prev is the current arr1[i]
                cost = dfs(i+1, arr1[i]);
            }

            // Otherwise, find the smallest number in arr2 which greater than prev (upper_bound)
            auto it = upper_bound(arr2.begin(), arr2.end(), prev);
            // Replace arr1[i] with that *it number
            if (it != arr2.end()) {
                cost = min(cost, 1 + dfs(i+1, *it));
            }

            memo[make_pair(i, prev)] = cost;
            return cost;
        };

        // Start with i = 0 and prev is -1 (always smaller than starting point)
        int ans = dfs(0, -1);

        return ans < 2001 ? ans : -1;
    }
};
