/*
https://leetcode.com/problems/contiguous-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> pos;
        pos[0] = -1;

        int cnt0 = 0, cnt1 = 0;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] == 0) cnt0++;
            else cnt1++;

            if (pos.count(cnt0 - cnt1)){
                ans = max(ans, i - pos[cnt0 - cnt1]);
            } else {
                pos[cnt0 - cnt1] = i;
            }
        }

        return ans;
    }
};
