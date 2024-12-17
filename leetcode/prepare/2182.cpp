/*
https://leetcode.com/problems/construct-string-with-repeat-limit/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char c: s) freq[c-'a']++;

        string res = "";
        int currCharIndex = 25;
        while (currCharIndex >= 0) {
            if (freq[currCharIndex] == 0) {
                currCharIndex--;
                continue;
            }

            int use = min(freq[currCharIndex], repeatLimit);
            res.append(use, 'a' + currCharIndex);
            freq[currCharIndex] -= use;

            // Need smaller char next
            if (freq[currCharIndex] > 0) {
                int smallerCharIndex = currCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }
                if (smallerCharIndex < 0) break; // no more valid to add
                // Add one smaller char if possible
                res.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }
        return res;
    }
};
