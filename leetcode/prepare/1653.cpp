/*
https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int N = s.size();
        vector<int> prefix(N, 0);
        vector<int> suffix(N, 0);
        for (int i = 1; i < N; ++i) {
            prefix[i] = prefix[i-1] + (s[i-1] == 'b' ? 1 : 0);
        }
        for (int i = N-2; i >= 0; --i) {
            suffix[i] = suffix[i+1] + (s[i+1] == 'a' ? 1 : 0);
        }
        int ans = INT_MAX;
        for (int i = 0; i < N; ++i) {
            ans = min(ans, prefix[i]+suffix[i]);
        }
        return ans;
    }
};
