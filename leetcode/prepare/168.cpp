/*
https://leetcode.com/problems/excel-sheet-column-title/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n) {
            n--;
            ans.push_back('A' + n%26);
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
