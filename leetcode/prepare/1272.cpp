/*
https://leetcode.com/problems/remove-interval/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        for (auto& interval: intervals) {
            if (interval[0] >= toBeRemoved[1] || interval[1] <= toBeRemoved[0])
                ans.push_back(interval);
            else {
                if (interval[0] < toBeRemoved[0]) ans.push_back({interval[0], toBeRemoved[0]});
                if (interval[1] > toBeRemoved[1]) ans.push_back({toBeRemoved[1], interval[1]});
            }
        }
        return ans;
    }
};
