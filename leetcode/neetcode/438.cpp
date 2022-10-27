#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        
        vector<int> dp(26, 0);
        for (auto c: p) {
            dp[c-'a'] += 1;
        }
        
        vector<int> ds(26, 0);
        for (int i = 0; i < p.size(); i++) {
            ds[s[i] - 'a'] += 1;
        }
        
        vector<int> res;
        if (ds == dp) res.push_back(0);
        for (int i = p.size(); i < s.size(); i++) {
            ds[s[i-p.size()] - 'a'] -= 1;
            ds[s[i] - 'a'] += 1;
            
            if (ds == dp) res.push_back(i - p.size() + 1);
        }
        return res;
    }
};
