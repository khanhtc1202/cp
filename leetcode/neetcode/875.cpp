#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = (right - left) / 2 + left;
            int time = 0;
            for (auto pile: piles) {
                time += pile / mid + (pile % mid != 0);
            }

            if (time <= h) right = mid;
            else left = mid+1;
        }
        return right;
    }
};
