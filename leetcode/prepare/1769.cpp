/*
https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        int leftBalls = 0, leftMoves = 0;
        int rightBalls = 0, rightMoves = 0;

        for (int i = 0; i < n; ++i) {
            // left pass
            ans[i] += leftMoves;
            leftBalls += boxes[i] - '0'; // +1 if it's a ball at i
            leftMoves += leftBalls; // + number of balls from left up to now

            // right pass: do the same
            int j = n - 1 - i;
            ans[j] += rightMoves;
            rightBalls += boxes[j] - '0';
            rightMoves += rightBalls;
        }

        return ans;
    }
};
