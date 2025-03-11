/*
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int start = 0, end = 0;
        int cnt = 0, n = s.size();
        unordered_map<char,int> check;
        while (end < n) {
            char c = s[end];
            ++check[c];
            while (check.size() == 3) {
                // from e to end of s, all char can combine with current string as valid result
                cnt += n - end;
                char sChar = s[start];
                if (--check[sChar] == 0) {
                    check.erase(sChar);
                }
                ++start;
            }
            ++end;
        }
        return cnt;
    }
};
