#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, cnt = 0;
        unordered_map<int, int> sums;
        sums[0] = 1;

        for (auto x : nums) {
            sum += x;
            // cnt += sums[k-sum];
            if (sums.find(sum-k) != sums.end()) {
                cnt += sums[sum-k];
            }
            sums[sum]++;
        }
        return cnt;
    }
};
