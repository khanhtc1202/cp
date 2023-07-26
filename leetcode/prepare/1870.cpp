/*
https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        auto calTime = [&](int speed) -> double {
            double time = 0.0;
            for (int i = 0; i < n; ++i) {
                double t = (double) dist[i] / (double) speed;
                time += (i == n - 1 ? t : ceil(t));
            }
            return time;
        };

        int l = 1, r = 1e7, ans = -1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (calTime(mid) <= hour) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
