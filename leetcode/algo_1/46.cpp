#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> comb;

    void backtrack(int i, vector<int>& nums) {
        if (comb.size() == nums.size()) {
            ans.push_back(comb);
            return;
        }
        
        for (int j = i+1; j <= nums.size(); j++) {
            comb.push_back(j);
            backtrack(i+1, nums);
            comb.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};
