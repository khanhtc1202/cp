/*
https://leetcode.com/problems/first-unique-character-in-a-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> chars(26, {0, -1});
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            chars[c-'a'].first++;
            chars[c-'a'].second = i;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (chars[i].first == 1)
                ans = min(ans, chars[i].second);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
