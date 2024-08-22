/*
https://leetcode.com/problems/number-complement/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        int lef = num, bit = 1;
        while (lef != 0) {
            num = num ^ bit;
            bit = bit << 1;
            lef = lef >> 1;
        }
        return num;
    }
};
