/*
https://leetcode.com/problems/count-total-number-of-colored-cells/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        return 1 + (long long)n * (n - 1) * 2;
    }
};
