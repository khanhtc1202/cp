/*
https://leetcode.com/problems/largest-3-same-digit-number-in-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int cnt = 1;
        char prev = num[0], maxd = ' ';
        for (int i = 1; num[i] != '\0'; ++i) {
            char c = num[i];
            cnt = (c == prev) ? cnt+1 : 1;
            if (cnt == 3 && c > maxd) maxd = c;
            prev = c;
        }
        if (maxd == ' ') return "";
        return {maxd, maxd, maxd};
    }
};
