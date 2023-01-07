#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        function<void(int)> backtrack = [&](int cnt) -> void {
            if (cnt == n) {
                // do not add duplicated permutation.
                // TODO: find a better way to remove dup.
                for (int i = 0; i < ans.size(); i++)
                    if (ans[i] == nums) return;

                ans.push_back(nums);
                return;
            }

            for (int i = cnt; i < n; i++) {
                if (i != cnt && nums[i] == nums[cnt]) continue;

                swap(nums[i], nums[cnt]);
                backtrack(cnt+1);
                swap(nums[i], nums[cnt]);
            }
        };

        backtrack(0);
        return ans;
    }
};
