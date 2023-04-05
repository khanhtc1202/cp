/*
https://leetcode.com/problems/excel-sheet-column-number/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int res = 0, unit = 0;
        for (int i = n-1; i > -1; i--) {
            res += ((columnTitle[i] - 'A' + 1) * pow(26, unit++));
        }
        return res;
    }
};
