/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(unsigned left, unsigned right) {
        if (left==0 || countl_zero(left)!=countl_zero(right)) return 0;
        return left & right & -(1<<(32-countl_zero(right-left)));
    }
};
