/*
https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int i = 2; i < nums.size(); ++i) {
            if ((nums[i-2]+nums[i])*2 == nums[i-1])
                ++ans;
        }
        return ans;
    }
};
