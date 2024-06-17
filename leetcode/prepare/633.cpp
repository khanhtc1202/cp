/*
https://leetcode.com/problems/sum-of-square-numbers/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) return true;
        int N = sqrt(c);
        for (int i = 1; i <= N; ++i) {
            int temp = c - (i*i);
            int x = sqrt(temp);
            if (x*x == temp) return true;
        }
        return false;
    }
};
