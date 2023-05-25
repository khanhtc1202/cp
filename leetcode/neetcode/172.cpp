/*
https://leetcode.com/problems/factorial-trailing-zeroes/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while (n) {
            cnt += n / 5;
            n /= 5;
        }
        return cnt;
    }
};
