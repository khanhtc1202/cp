/*
https://leetcode.com/problems/longest-palindrome/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int oddCnt = 0;
        unordered_map<char,int> freq;

        for (char c: s) {
            freq[c]++;

            if (freq[c] % 2 == 1) {
                oddCnt++;
            } else {
                oddCnt--;
            }
        }

        if (oddCnt > 0) return s.size() - oddCnt + 1;
        else return s.size();
    }
};
