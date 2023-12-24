/*
https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int op0 = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if ((i&1) == ((s[i]-'0')&1))
                op0++;
        }
        return min(op0, n - op0);
    }
};
