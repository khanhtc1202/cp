/*
https://leetcode.com/problems/combination-sum-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        int N = candidates.size();

        sort(candidates.begin(), candidates.end());

        function<void(int, int)> backtrack = [&](int target, int index) -> void {
            if (target == 0) {
                res.push_back(comb);
                return;
            }

            for (int i = index; i < N && target >= candidates[i]; ++i) {
                if (i == index || candidates[i] != candidates[i-1]) {
                    comb.push_back(candidates[i]); // add cand[i] to current comb
                    backtrack(target - candidates[i], i+1);
                    comb.pop_back();
                }
            }
        };

        backtrack(target, 0);
        return res;
    }
};
