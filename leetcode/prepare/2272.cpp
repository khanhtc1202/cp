/*
https://leetcode.com/problems/substring-with-largest-variance/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int count[26] = {}, ans = 0;
        for (auto c: s) count[c - 'a']++;

        // Kadane idea to find the largest variance
        // instead of the largest sum, we find the largest difference (major - minor)
        // and we reset the major and minor when: major < minor and there are still minor left
        auto variance = [&](char major, char minor) {
            int majorCnt = 0, minorCnt = 0, restMinor = count[minor-'a'], ans = 0;
            for (auto c: s) {
                if (c == major) majorCnt++;
                if (c == minor) minorCnt++, restMinor--;

                if (minorCnt > 0) ans = max(ans, majorCnt - minorCnt);
                if (majorCnt < minorCnt && restMinor > 0) {
                    majorCnt = 0;
                    minorCnt = 0;
                }
            }
            return ans;
        };

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i == j || count[i] == 0 || count[j] == 0) continue;

                ans = max(ans, variance('a'+i, 'a'+j));
            }
        }
        return ans;
    }
};
