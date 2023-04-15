/*
https://leetcode.com/problems/split-array-largest-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = 1e9;
        int ans;

        auto check = [&](int s) -> bool {
            int i = 0;
            int tmp = 0;
            int cnt = 1;
            for (int i = 0; i < nums.size(); i++) {
                if (tmp + nums[i] <= s) {
                    tmp += nums[i];
                    continue;
                }

                cnt++; 
                tmp = nums[i];
            }
            return cnt <= k; 
        };

        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
