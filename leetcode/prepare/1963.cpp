/*
https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int stkSize = 0;
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            char ch = s[i];
            if (ch == '[') {
                stkSize++;
            } else {
                if (stkSize > 0) stkSize--;
            }
        }
        return (stkSize+1)/2;
    }
};
