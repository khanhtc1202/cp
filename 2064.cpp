/*
https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canDist(int n, vector<int>& q, int x) {
        int j = 0;
        int remain = q[j];
        for (int i = 0; i < n; ++i) {
            if (remain <= x) {
                ++j; // Can fill all remain of current product to store i
                if (j == q.size()) {
                    // All filled
                    return true;
                } else {
                    remain = q[j]; // next product
                }
            } else {
                remain -= x; // distribute x to the i-th store
            }
        }
        return false;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int left = 0;
        int right = *max_element(q.begin(), q.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDist(n, q, mid)) {
                right = mid; // Find the smaller x
            } else {
                left = mid + 1; // Find the bigger x
            }
        }
        return left;
    }
};
