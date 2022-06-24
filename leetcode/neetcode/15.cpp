#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        int curSum = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            // remove possible same nums[i]
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int s = i+1, e = nums.size()-1;
            while (s < e) {
                curSum = nums[i] + nums[s] + nums[e];
                if (curSum == 0) {
                    out.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    while (nums[s] == nums[s-1] && s < e)
                        s++;
                } else if (curSum < 0) {
                    s++;
                } else {
                    e--;
                }
            }
        }
        return out;
    }
};
