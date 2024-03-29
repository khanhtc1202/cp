#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int p = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                if (p != -1) return false;
                p = i-1;
            }
        }
        return p == -1 || p == 0 || p == nums.size() - 2 
            || nums[p-1] <= nums[p+1] || nums[p] <= nums[p+2];
    }
};
