#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        auto robb = [&](int start, int end) -> int {
            if (end - start == 1)
                return max(nums[start], nums[end]);

            int prev2 = 0;
            int prev1 = 0;
            int res = 0;
            for (int i = start; i <= end; i++) {
                res = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = res;
            }
            return res;
        };

        return max(robb(0, nums.size()-2), robb(1, nums.size()-1));
    }
};
