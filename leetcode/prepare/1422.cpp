/*
https://leetcode.com/problems/maximum-score-after-splitting-a-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int temp = s[0] == '0' ? 1 : 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1') temp++;
        }

        int ans = temp;
        for (int i = 1; i < s.size()-1; ++i) {
            if (s[i] == '0') temp++; // add zero to left mean ans increas
            else temp--; // add one to left mean ans decrease

            ans = max(ans, temp);
        }
        return ans;
    }
};
