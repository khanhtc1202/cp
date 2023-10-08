/*
https://leetcode.com/problems/max-dot-product-of-two-subsequences/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // Special cases
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for (auto num: nums1) max1 = max(max1, num), min1 = min(min1, num);
        for (auto num: nums2) max2 = max(max2, num), min2 = min(min2, num);

        if (max1 < 0 && min2 > 0) return max1 * min2;
        if (max2 < 0 && min1 > 0) return max2 * min1;

        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp = vector(n1+1, vector(n2+1, 0));

        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                // Get number at index (i-1) from nums1 and (j-1) from nums2
                int use = nums1[i-1] * nums2[j-1] + dp[i-1][j-1];
                // Answer for i numbers from n1 and j numbers from n2
                // would be max of use and answer in case not use (j-1)
                // and in case not use (i-1).
                dp[i][j] = max(use, max(dp[i][j-1], dp[i-1][j]));
            }
        }
        return dp[n1][n2];
    }
};
