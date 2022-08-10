#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        int n = candidates.size();

        function<void(int, int)> backtrack = [&](int i, int sum) -> void {
            if (sum > target) return;

            if (sum == target) {
                res.push_back(tmp);
                return;
            }

            for (int j = i; j < n; j++) {
                tmp.push_back(candidates[j]);
                backtrack(j, sum+candidates[j]);
                tmp.pop_back();
            }
        };

        backtrack(0, 0);
        return res;
    }
};
