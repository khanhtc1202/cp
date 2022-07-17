#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i];
        }

        if (pre[n-1] - pre[0] == 0)
            return 0;

        for (int i = 1; i < n-1; i++) {
            if (pre[i-1] == pre[n-1] - pre[i])
                return i; 
        }

        if (pre[n-2] == 0)
            return n-1;

        return -1;
    }

    int pivot(vector<int>& nums) {
        int sum = 0;
        for (auto& x: nums) sum += x;
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == sum - nums[i] - leftSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
