/*
https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string s, string sw) {
        int currWordPos = 1;
        int currIndex = 0;
        int len = s.size();

        while (currIndex < len) {
            // Skip leading space
            while (currIndex < len && s[currIndex] == ' ') {
                currIndex++;
                currWordPos++; // single space so this run once
            }

            // Check prefix
            int match = 0;
            while (currIndex < len && match < sw.size() && s[currIndex] == sw[match]) {
                currIndex++;
                match++;
            }

            // Found
            if (match == sw.size()) {
                return currWordPos;
            }

            // Skip the rest of the current word
            while (currIndex < len && s[currIndex] != ' ') {
                currIndex++;
            }
        }
        return -1;
    }
};
