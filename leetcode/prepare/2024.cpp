/*
https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        auto count = [&](char c) {
            int l = 0, r = 0, cnt = 0;
            int ans = 0;
            for (; r < n; ++r) {
                cnt += answerKey[r] == c;
                while (cnt > k) cnt -= answerKey[l++] == c;
                ans = max(ans, r - l + 1);
            }
            return ans;
        };
        return max(count('T'), count('F'));
    }
};
