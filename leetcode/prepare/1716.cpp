/*
https://leetcode.com/problems/calculate-money-in-leetcode-bank/?
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arithmeticSum(int lead, int last, int cnt) {
        return cnt * (lead+last) / 2;
    }

    int totalMoney(int n) {
        int q = n / 7, r = n % 7;
        return arithmeticSum(28, 28+(q-1)*7, q) + arithmeticSum(1+q, r+q, r);
    }
};
