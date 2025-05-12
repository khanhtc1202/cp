/*
https://leetcode.com/problems/count-symmetric-integers/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int x = low; x <= high; ++x) {
            if (x < 100 && x % 11 == 0) {
                ans++;
            } else if (1000 < x && x < 10000) {
                int left = x / 1000 + (x % 1000) / 100;
                int right = (x % 100) / 10 + (x % 10);
                if (left == right) ans++;
            }
        }
        return ans;
    }
};
