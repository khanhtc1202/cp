/*
https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        vector<int> indegree(n, 0);
        function<void(int, int)> backtrack = [&](int i, int count) -> void {
            if (i == requests.size()) {
                for (int k = 0; k < n; k++)
                    if (indegree[k])
                        return;

                ans = max(ans, count);
                return;
            }

            // accept this request
            indegree[requests[i][0]]--;
            indegree[requests[i][1]]++;

            // try next request in condition of accepted this request
            backtrack(i+1, count+1);

            // backtrack
            indegree[requests[i][0]]++;
            indegree[requests[i][1]]--;

            // try next request in condition of not accepted this request
            backtrack(i+1, count);
        };

        backtrack(0, 0);
        return ans;
    }
};
