/*
https://leetcode.com/problems/trapping-rain-water/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> L(n, 0), R(n, 0);
        for (int i = 1; i < n; i++) {
            L[i] = max(L[i-1], height[i-1]);
        }
        for (int i = n-2; i > -1; i--) {
            R[i] = max(R[i+1], height[i+1]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int tmp = min(L[i], R[i]);
            res += max(0, tmp - height[i]);
        }
        return res;
    }

    int _trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int l = 0, r = n-1;
        int lmax = height[0], rmax = height[n-1];
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= lmax) {
                    lmax = height[l];
                } else {
                    res += (lmax - height[l]);
                }
                l++;
            } else {
                if (height[r] >= rmax) {
                    rmax = height[r];
                } else {
                    res += (rmax - height[r]);
                }
                r--;
            }
        }
        return res;
    }
};
