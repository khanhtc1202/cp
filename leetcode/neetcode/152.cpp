#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int res = curMax, tmpMax;
        for (int i = 1; i < nums.size(); i++) {
            tmpMax = max(nums[i], max(curMax*nums[i], curMin*nums[i]));
            curMin = min(nums[i], min(curMax*nums[i], curMin*nums[i]));
            curMax = tmpMax;
            res = max(curMax, res);
        }
        return res;
    }
};
