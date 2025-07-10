/*
https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), ans = 0;
        for (int i = 0, t1 = 0, t2 = 0; i < n; ++i) {
            int left1 = i == 0 ? 0 : endTime[i-1]; // end of previous mtg
            int right1 = i == n - 1 ? eventTime : startTime[i+1]; // start of next mtg
            // possible to shift current mtg outter range
            if (endTime[i] - startTime[i] <= t1) {
                ans = max(ans, right1 - left1);
            }
            
            // update t1 as maximum time slot of the outter left range
            t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i-1]));

            // possible to shift current mtg in the inner range
            ans = max(ans, right1 - left1 - (endTime[i] - startTime[i]));

            int left2 = i == n - 1 ? 0 : endTime[n-i-2];
            int right2 = i == 0 ? eventTime : startTime[n-i];
            if (endTime[n-i-1] - startTime[n-i-1] <= t2) {
                ans = max(ans, right2 - left2);
            }
            t2 = max(t2, (i == 0 ? eventTime : startTime[n-i]) - endTime[n-i-1]);
        }
        return ans;
    }
};
