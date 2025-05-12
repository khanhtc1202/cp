/*
https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        bool f1 = false, f2 = false;
        for (int& x: nums1) {
            sum1 += x;
            if (x == 0) f1 = true, sum1++;
        }
        for (int& x: nums2) {
            sum2 += x;
            if (x == 0) f2 = true, sum2++;
        }
        if ((!f1 && sum1 < sum2) || (!f2 && sum2 < sum1))
            return -1;
        return max(sum1, sum2);
    }
};
