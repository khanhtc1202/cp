/*
https://leetcode.com/problems/bag-of-tokens/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n-1;
        int score = 0;
        for (int p = 0; p < n; ++p) {
            if (tokens[i] <= power) {
                ++score;
                power -= tokens[i++];
            } else if (score > 0 && p != n-1) {
                // If last play is a buy, avoid that buy
                --score;
                power += tokens[j--];
            }
        }
        return score;
    }
};
