/*
https://leetcode.com/problems/ugly-number-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums(n);
        uglyNums[0] = 1;

        int indexMulOf2 = 0, indexMulOf3 = 0, indexMulOf5 = 0;
        int nextMulOf2 = 2, nextMulOf3 = 3, nextMulOf5 = 5;

        for (int i = 1; i < n; ++i) {
            // find next ugly number
            int nextUglyNum = min({nextMulOf2, nextMulOf3, nextMulOf5});
            uglyNums[i] = nextUglyNum;

            // Update next ugly number pointers
            if (nextUglyNum == nextMulOf2) {
                indexMulOf2++;
                nextMulOf2 = uglyNums[indexMulOf2] * 2; // precompute next mul of 2
            }

            if (nextUglyNum == nextMulOf3) {
                indexMulOf3++;
                nextMulOf3 = uglyNums[indexMulOf3] * 3;
            }

            if (nextUglyNum == nextMulOf5) {
                indexMulOf5++;
                nextMulOf5 = uglyNums[indexMulOf5] * 5;
            }
        }
        return uglyNums[n-1];
    }
};
