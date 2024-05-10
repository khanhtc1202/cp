/*
https://leetcode.com/problems/k-th-smallest-prime-fraction/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0, r = 1.0, mid;

        while (l <= r) {
            mid = l + (r-l)/2;
            int j = 1, total = 0, num = 0, den = 0;
            double maxFrac = 0;
            // Find the number of frac which smaller than mid
            for (int i = 0; i < n; ++i) {
                while (j < n && arr[i] >= arr[j]*mid) {
                    ++j;
                }

                // With j is the number ensure that arr[i]/arr[j]
                // is the biggest which smaller than mid
                // Add (n-j) as number of smaller frac with i as numerator
                total += n - j;

                // Store the ans
                if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i, den = j;
                }
            }

            // Update binary search range
            if (total == k) {
                return {arr[num], arr[den]};
            }
            if (total > k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return {};
    }
};
