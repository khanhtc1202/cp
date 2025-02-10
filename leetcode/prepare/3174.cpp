/*
https://leetcode.com/problems/clear-digits/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for (auto c: s) {
            if (isdigit(c))
                ans.pop_back();
            else ans.push_back(c);
        }
        return ans;
    }
};
