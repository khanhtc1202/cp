/*
https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> cover(n+1);

        for (int i = 0; i < n+1; ++i) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);

            // Store the farest to the right if start at "start".
            cover[start] = max(cover[start], end);
        }

        int taps = 0;
        int currEnd = 0;
        int nextEnd = 0;

        for (int i = 0; i < n+1; ++i) {
            // The current index can't be covered
            if (i > nextEnd) return -1;

            if (i > currEnd) {
                taps++;
                currEnd = nextEnd;
            }

            // Update the farest to the right
            nextEnd = max(nextEnd, cover[i]);
        }

        return taps;
    }
};
