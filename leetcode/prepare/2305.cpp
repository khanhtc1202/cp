/*
https://leetcode.com/problems/fair-distribution-of-cookies/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribute(k, 0);
        function<int(int, int)> backtrack = [&](int i, int zero) -> int {
            if (cookies.size() - i < zero) {
                return INT_MAX;
            }

            if (i == cookies.size()) {
                return *max_element(distribute.begin(), distribute.end());
            }

            int ans = INT_MAX;
            for (int j = 0; j < k; j++) {
                // Check whether this child j has cookies or not
                zero -= distribute[j] == 0 ? 1 : 0;
                // Give cookies bag i to child j
                distribute[j] += cookies[i];

                ans = min(ans, backtrack(i+1, zero));

                distribute[j] -= cookies[i];
                zero += distribute[j] == 0 ? 1 : 0;
            }
            return ans;
        };

        return backtrack(0, k);
    }
};
