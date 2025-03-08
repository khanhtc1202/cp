/*
https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, count = 0, ans = INT_MAX;
        for (int r = 0; r < blocks.size(); ++r) {
            if (blocks[r] == 'W')
                ++count; // count white

            if (r - l + 1 == k) { // block of k char
                ans = min(ans, count); // update min
                if (blocks[l] == 'W')
                    --count; // remove left most
                ++l;
            }
        }
        return ans;
    }
};
