#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last = 0, cur = 0;
        while (cur < nums.size()) {
            if (nums[cur] != 0) {
                swap(nums[cur], nums[last]);
                last++;
            }
            cur++;
        }
    }
};
