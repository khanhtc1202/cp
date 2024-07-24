/*
https://leetcode.com/problems/sort-the-jumbled-numbers/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto rx = [&](int x) -> int {
            int out = 0, unit = 1;
            // edge case
            if (x == 0) return mapping[0];
            while (x != 0) {
                out = unit * mapping[x % 10] + out;
                unit *= 10;
                x /= 10;
            }
            return out;
        };

        vector<pair<int,int>> a;
        for (int i = 0; i < nums.size(); ++i) {
            a.push_back({rx(nums[i]), i});
        }

        sort(a.begin(), a.end());
        vector<int> ans;
        for (int i = 0; i < a.size(); ++i) {
            ans.push_back(nums[a[i].second]);
        }
        return ans;
    }
};
