#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) nums[idx] *= -1;
        }
        
        vector<int> out;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) out.push_back(i+1);
        }
        return out;
    }
};
