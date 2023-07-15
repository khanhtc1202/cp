/*
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = 0, totalWeight = 0;
        for (auto w: weights) {
            maxWeight = max(maxWeight, w);
            totalWeight += w;
        }

        auto feasible = [&](int cap) -> bool {
            int daysNeed = 1, load = 0;
            for (auto w: weights) {
                load += w;
                if (load > cap) {
                    daysNeed++;
                    load = w;
                }
            }
            return daysNeed <= days;
        };

        int l = maxWeight, r = totalWeight;
        while (l < r) {
            int mid = l + (r - l)/2;
            if (feasible(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
