/*
https://leetcode.com/problems/magnetic-force-between-two-balls/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if we can place "balls" at "p" positions
    // with each ball having at least "dis" gap
    static bool canPlace(vector<int>& p, int balls, int dis) {
        int prev = p[0], placed = 1;
        for (int i = 1; i < p.size() && placed < balls; ++i) {
            int curr = p[i];
            if (curr - prev >= dis) {
                ++placed;
                prev = curr;
            }
        }
        return placed == balls;
    }

    int maxDistance(vector<int>& position, int m) {
        int ans = 0;
        int N = position.size();
        sort(position.begin(), position.end());
        int l = 1, r = ceil(position[N-1] / (m-1.0));
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (canPlace(position, m, mid)) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
};
