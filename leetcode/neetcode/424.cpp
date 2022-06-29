#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        auto solve = [&](char c) -> void {
            int cnt = 0, r = 0;
            for (int l = 0; l < s.size(); l++) {
                while (r < s.size() && (cnt + (s[r] != c)) <= k) {
                    cnt += (s[r] != c);
                    r++;
                }
                ans = max(ans, r-l);
                cnt -= (s[l] != c);
            }
        };
        for (int i = 0; i < 26; i++) {
            solve(i + 'A');
        }
        return ans;
    }
};
