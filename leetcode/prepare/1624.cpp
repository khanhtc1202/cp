/*
https://leetcode.com/problems/largest-substring-between-two-equal-characters/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);
        int ans = -1;
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            if (first[c] != -1) {
                ans = max(ans, i - first[c] - 1);
            } else {
                first[c] = i;
            }
        }
        return ans;
    }
};
