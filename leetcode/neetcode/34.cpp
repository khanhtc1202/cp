#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        
        int l = 0, r = nums.size() - 1;
        int head, tail;
        while (l <= r) {
            int m = (l+r) / 2;
            if (nums[m] >= target) {
                r = m - 1;
            } else l = m + 1;
        }
        head = l;

        l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l+r) / 2;
            if (nums[m] > target) {
                r = m - 1;
            } else l = m + 1;
        }
        tail = r;

        if (head <= tail && nums[head] == target)
            return {head, tail};
        return {-1, -1};
    }
};
