#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        int sz = s.size();
        vector<vector<bool>> dp = vector<vector<bool>>(sz, vector<bool>(sz, false));
        
        function<void(int)> backtrack = [&](int idx) -> void {
            if (idx >= sz) {
                res.push_back(tmp);
                return;
            }
            
            for (int i = idx; i < sz; i++) {
                if (s[idx] == s[i] && (i - idx <= 2 || dp[idx+1][i-1])) {
                    dp[idx][i] = true;
                    tmp.push_back(s.substr(idx, i-idx+1));
                    backtrack(i+1);
                    tmp.pop_back();
                }
            }
        };
        
        backtrack(0);
        return res;
    }
};
