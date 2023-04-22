/*
https://leetcode.com/problems/reverse-integer/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        if (x < 0) str += "-";
        ::reverse(str.begin(), str.end());
        double ans = stod(str);
        return ans < INT_MIN || ans > INT_MAX ? 0 : (int)ans;
    }
};
