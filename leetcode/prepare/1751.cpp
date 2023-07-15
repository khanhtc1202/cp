/*
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();

        auto findNext = [&](int index, int target) -> int {
            int l = index + 1, r = n;
            while (l < r) {
                int mid = (l+r) / 2;
                if (events[mid][0] <= target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };

        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int idx = n-1; idx >= 0; --idx) {
            for (int count = 1; count <= k; ++count) {
                int next = findNext(idx, events[idx][1]);

                dp[idx][count] = max(dp[idx+1][count], dp[next][count-1] + events[idx][2]);
            }
        }

        return dp[0][k];
    }

    int maxValue_TopDown(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();

        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        function<int(int, int, int)> dfs = [&](int idx, int count, int prev_end) -> int {
            if (count == 0 || idx == n)
                return 0;

            // In case prev_end is passed, we can skip the current event
            if (prev_end >= events[idx][0]) {
                return dfs(idx + 1, count, prev_end);
            }

            if (dp[idx][count] != -1)
                return dp[idx][count];

            dp[idx][count] = max(dfs(idx+1, count-1, events[idx][1]) + events[idx][2], dfs(idx+1, count, prev_end));
            return dp[idx][count];
        };

        return dfs(0, k, -1);
    }
};
