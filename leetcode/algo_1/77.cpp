#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> comb;

    void backtrack(int i, int n, int k) {
        if (comb.size() == k) {
            ans.push_back(comb);
            return;
        }

        for (int j = i+1; j <= n; j++) {
            comb.push_back(j);
            backtrack(j, n, k);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(0, n, k);
        return ans;
    }
};
