/*
https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int sz = 2*n - 1;
        vector<int> ans(sz, 0);
        vector<int> used(n+1, 0);
        function<bool(int)> backtrack = [&](int idx) -> bool {
            // Fulfilled
            if (idx == sz) return true;
            // ans[idx] is filled, try the next index
            if (ans[idx]) return backtrack(idx+1);

            for (int i = n; i > 0; i--) {
                // Used number is ignored
                if (used[i]) continue;
                // Skip if the idx+i is over ans size or ans[idx+i] is filled
                if (i != 1 && (idx+i >= sz || ans[idx+i])) continue;

                used[i] = 1;
                // Fill ans[idx] & ans[idx+i]
                ans[idx] = i;
                if (i != 1) ans[idx+i] = i;

                // Recursive call and return true if found a good fill
                if (backtrack(idx+1)) return true;

                // Else, backtrack and try other
                ans[idx] = 0;
                if (i != 1) ans[idx+i] = 0;
                used[i] = 0;
            }
            // Current fill false
            return false;
        };

        backtrack(0);
        return ans;
    }
};
