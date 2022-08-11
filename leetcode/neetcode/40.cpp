#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        function<void(int, int)> backtrack = [&](int i, int sum) -> void {
            if (sum > target) return;

            if (sum == target) {
                res.push_back(tmp);
                return;
            }

            for (int j = i+1; j < n; j++) {
                if (j != i+1 && candidates[j] == candidates[j-1]) continue;

                tmp.push_back(candidates[j]);
                backtrack(j, sum+candidates[j]);
                tmp.pop_back();
            }
        };

        backtrack(-1, 0);
        return res;
    }
};
