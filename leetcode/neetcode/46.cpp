#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n);

        vector<vector<int>> res;
        vector<int> tmp;

        function <void(int)> backtrack = [&](int i) -> void {
            if (i == n) {
                res.push_back(tmp);
                return;
            }

            for (int j = 0; j < n; j++) {
                if (!seen[j]) {
                    tmp.push_back(nums[j]); seen[j] = true;
                    backtrack(i+1);
                    tmp.pop_back(); seen[j] = false;
                }
            }
        };

        backtrack(0);
        return res;
    }
};
