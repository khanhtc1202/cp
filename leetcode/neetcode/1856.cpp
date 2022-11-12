#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int ans = 0; int k = 1e9+7;
        for (int i = 0; i < nums.size(); i++) {
            int cmin = nums[i];
            int csum = 0;
            for (int j = i; j < nums.size(); j++) {
                cmin = min(cmin, nums[j]);
                csum += nums[j];
                csum %= k;
                ans = max(ans, (cmin * csum)%k);
            }
        }
        return ans;
    }
};
