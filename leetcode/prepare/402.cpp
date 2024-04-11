/*
https://leetcode.com/problems/remove-k-digits/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        string ans = "";
        for (auto c: num) {
            while (ans != "" && c < ans.back() && k > 0) {
                ans.pop_back();
                --k;
            }
            ans.push_back(c);
        }
        // cout << ans << endl;
        while (k > 0) {
            ans.pop_back();
            --k;
        }
        int i = 0, m = ans.size();
        while (ans[i] == '0' && i < m) ++i;
        return i == m ? "0" : ans.substr(i);
    }
};
