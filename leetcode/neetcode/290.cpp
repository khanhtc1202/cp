/*
Problem desc: https://leetcode.com/problems/word-pattern/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> charMap;
        unordered_map<string, int> strMap;
        int i = 0, j = 0;
        int idxi = 0, idxj = 0;
        while (idxi < pattern.size() && idxj < s.size()) {
            char c = pattern[idxi]; idxi++;
            if (charMap.find(c) == charMap.end()) {
                charMap[c] = i;
                i++;
            }
            string tmp;
            while (idxj < s.size() && s[idxj] != ' ') {
                tmp += s[idxj];
                idxj++;
            }
            while (s[idxj] == ' ') idxj++;
            if (strMap.find(tmp) == strMap.end()) {
                strMap[tmp] = j;
                j++;
            }
            if (charMap[c] != strMap[tmp]) return false;
        }
        return idxi == pattern.size() && idxj == s.size();
    }
};
