/*
https://leetcode.com/problems/minimum-time-to-repair-cars/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int minR = *min_element(ranks.begin(), ranks.end());
        long long l = 1, r = 1LL * minR * cars * cars;
        int n = ranks.size();
        while (l < r) {
            long long mid = l + (r-l)/2;
            long long repaired = 0;
            for (int i = 0; i < n; ++i) {
                repaired += sqrt(1.0 * mid / ranks[i]);
            }
            if (repaired >= cars) {
                r = mid;
            } else l = mid+1;
        }
        return l;
    }
};
