#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int n = nums.size();

        function <void(int)> backtrack = [&](int i) -> void {
            if (i > n) return;

            res.push_back(tmp);
            for (int j = i+1; j < n; j++) {
                tmp.push_back(nums[j]);
                backtrack(j);
                tmp.pop_back();
            }
        };

        backtrack(-1);
        return res;
    }
    
    vector<vector<int>> subsetsOpt(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res = {{}};
        for (int i = 0; i < n; i++) {
            vector<vector<int>> tmp;
            for (auto sub: res) {
                sub.push_back(nums[i]);
                tmp.push_back(sub);
            }
            for (auto &x: tmp) res.emplace_back(x);
        }
        return res;
    }
};
