#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainders{{0, 0}};
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (!remainders.count(sum % k))
                remainders[sum % k] = i + 1;
            else if (remainders[sum % k] < i)
                return true; // sum from <i -> i contains at least 2 elements.
        }
        return false;
    }
};
