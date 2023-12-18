/*
https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = 0, max2 = 0, min1 = 1e4+1, min2 = 1e4+1;
        for (auto e: nums) {
            // Update max
            if (e > max1) {
                max2 = max1;
                max1 = e;
            } else if (e > max2) {
                max2 = e;
            }
            // Update min
            if (e < min1) {
                min2 = min1;
                min1 = e;
            } else if (e < min2) {
                min2 = e;
            }
        }
        return (max1*max2) - (min1*min2);
    }
};
