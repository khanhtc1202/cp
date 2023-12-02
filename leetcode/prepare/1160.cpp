/*
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int base[26] = {};
        for (auto c: chars) ++base[c-'a'];

        int ans = 0, cnt = 0;
        for (auto& w: words) {
            int freq[26] = {}; cnt = 0;
            bool possible = true;
            for (auto c: w) {
                ++cnt;
                if (++freq[c-'a'] > base[c-'a']) {
                    possible = false;
                    break;
                }
            }
            if (possible) ans += cnt;
        }
        return ans;
    }
};
