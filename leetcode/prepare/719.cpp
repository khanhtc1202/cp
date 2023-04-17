/*
https://leetcode.com/problems/find-k-th-smallest-pair-distance/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto countPairs = [&](int dis) -> int {
            int cnt = 0;
            int j = 0;
            for (int i = 0; i < nums.size(); i++) {
                while (j < i && nums[j] + dis < nums[i]) {
                    j++;
                }
                cnt += (i - j);
            }
            return cnt;
        };

        int l = 0, r = 1e6;
        int ans = 0;
        while (l <= r) {
            int mid = (r-l)/2 + l;
            if (countPairs(mid) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
