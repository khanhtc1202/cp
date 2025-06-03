/*
https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> can_open(n), has_box(n), used(n);
        for (int i = 0; i < n; ++i) {
            can_open[i] = (status[i] == 1);
        }

        queue<int> q;
        int ans = 0;
        for (int box: initialBoxes) {
            has_box[box] = true;
            if (can_open[box]) { // open right the way
                q.push(box);
                used[box] = true;
                ans += candies[box];
            }
        }

        while (!q.empty()) {
            int outter_box = q.front(); q.pop();
            // check key in outter_box
            for (int key: keys[outter_box]) {
                can_open[key] = true;
                // open the box if we have key and box not yet open
                if (!used[key] && has_box[key]) {
                    q.push(key);
                    used[key] = true;
                    ans += candies[key];
                }
            }
            // check contained box in outter_box
            for (int box: containedBoxes[outter_box]) {
                has_box[box] = true;
                if (!used[box] && can_open[box]) {
                    q.push(box);
                    used[box] = true;
                    ans += candies[box];
                }
            }
        }
        return ans;
    }
};
