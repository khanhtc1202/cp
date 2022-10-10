#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int cand = nums[0];
        for (auto num: nums) {
            if (cnt == 0) {
                cand = num;
            }
            cnt += (num == cand) ? 1 : -1;
        }
        return cand;
    }
};
