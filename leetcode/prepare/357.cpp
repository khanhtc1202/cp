/*
https://leetcode.com/problems/count-numbers-with-unique-digits/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        vector<int> acc(n+1);
        acc[1] = 10;
        for (int i = 2; i <= n; i++) {
            int tmp = 9, cnt = i;
            while (cnt > 1) {
                tmp *= (11 - cnt);
                cnt--;
            }
            acc[i] = acc[i-1] + tmp;
        }
        return acc[n];
    }
};
