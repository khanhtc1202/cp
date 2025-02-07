/*
https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colored;
        unordered_map<int, int> ball;
        vector<int> ans(queries.size(), 0);
        int idx = 0;
        for (auto q: queries) {
            int b = q[0], c = q[1];
            int pvc = ball[b];
            ball[b] = c;
            if (pvc != 0) {
                if (--colored[pvc] == 0)
                    colored.erase(pvc);
            }
            colored[c]++;
            ans[idx++] = colored.size();
        }
        return ans;
    }
};
