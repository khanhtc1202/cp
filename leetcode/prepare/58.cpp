/*
https://leetcode.com/problems/length-of-last-word/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (ans == 0) continue;
                return ans;
            }
            ans++;
        }
        return ans;
    }
};
