/*
https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        auto getSum = [&](int val) -> long {
            long sum = 0;
            if (val > index) {
                sum += (long)(val + val - index) * (index+1) /2;
            } else {
                sum += (long)(val+1) * val/2 + index - val + 1;
            }

            if (val >= n - index) {
                sum += (long)(val + val - n + 1 + index) * (n - index)/2;
            } else {
                sum += (long)(val + 1) * val / 2 + n - index - val;
            }

            return sum - val;
        };

        int l = 1, r = maxSum;
        while (l < r) {
            int mid = (l+r+1) / 2;
            if (getSum(mid) <= maxSum) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
