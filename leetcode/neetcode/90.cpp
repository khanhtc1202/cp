#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> tmp;

        function<void(int)> backtrack = [&](int i) -> void {
            res.push_back(tmp);

            for (int j = i+1; j < n; j++) {
                if (j != i+1 && nums[j] == nums[j-1]) continue;

                tmp.push_back(nums[j]);
                backtrack(j);
                tmp.pop_back();
            }
        };

        backtrack(-1);
        return res;
    }
};
