/*
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int countBouquets(vector<int>& b, int k, int d) {
        int cnt = 0, ans = 0;
        for (int i = 0; i < b.size(); ++i) {
            if (b[i] <= d) cnt++;
            else cnt = 0;

            if (cnt == k) ans++, cnt = 0;
        }
        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long)m*k) return -1;
        auto [min, max] = minmax_element(bloomDay.begin(), bloomDay.end()); 
        int l = *min, r = *max;
        int ans = 0;
        while (l <= r) {
            int mid = (l+r)/2;
            if (countBouquets(bloomDay, k, mid) >= m) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};
