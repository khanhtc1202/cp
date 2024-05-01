/*
https://leetcode.com/problems/reverse-prefix-of-word/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        if (word[0] == ch) return word;
        int p = 0, sz = word.size();
        while (p < sz && word[p] != ch) ++p;
        if (word[p] != ch) return word;
        int l = 0, r = p;
        while (l < r) swap(word[l++], word[r--]);
        return word;
    }
};
