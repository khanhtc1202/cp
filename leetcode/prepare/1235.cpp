/*
https://leetcode.com/problems/maximum-profit-in-job-scheduling/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        int n = profit.size();
        vector<tuple<int, int, int>> jobs(n);

        for (int i = 0; i < n; ++i)
            jobs[i] = {endTime[i], startTime[i], profit[i]};

        sort(jobs.begin(), jobs.end());
        vector<int> dp(n+1);

        for (int i = 0; i < n; ++i) {
            auto [endTime, startTime, profit] = jobs[i];
            int firstJBeforeI = upper_bound(jobs.begin(), jobs.begin()+i, startTime,
                // Find the first job that end before starting the job at startTime
                [&](int time, const auto& job) -> bool {
                    return time < get<0>(job);
                }) - jobs.begin();

            // Update (i+1) by compare
            // - do task job[i] = dp[firstJBeforeI]+profit_of_i
            // - do not do task job[i] = dp[i]
            dp[i+1] = max(dp[i], dp[firstJBeforeI]+profit);
        }
        return dp[n];
    }
};

class Solution1 {
public:
    using int3 = array<int, 3>;
    vector<int3> jobs; // (startTime, endTime, profit)
    vector<int> dp;
    vector<int> next;
    int n;

    void binary_search() {
        for (int i = 0; i < n; i++) {
            next[i] = upper_bound(jobs.begin()+i, jobs.end(),
                array<int, 3>{jobs[i][1], 0, 0}) - jobs.begin();
        }
    }

    int dfs(int i) {
        if (i == n) return 0;
        if (dp[i]!= -1) return dp[i];

        // take the job i
        int profit_w_i = jobs[i][2] + dfs(next[i]);

        // Skip the job i
        int profit_n_i = dfs(i+1);

        // Choose the maximum of profit_w_i & profit_n_i
        return dp[i] = max(profit_w_i, profit_n_i);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        n = startTime.size();
        jobs.assign(n, {-1, -1, -1});
        for (int i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end());
        // Initialize the 'next' vector with the correct size
        next.assign(n, -1);

        dp.assign(n+1, -1);
        binary_search();
        return dfs(0);
    }
};
