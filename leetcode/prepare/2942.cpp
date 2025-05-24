/*
https://leetcode.com/problems/find-words-containing-character/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int i = 0;
        for (auto& w: words) {
            for (auto& c: w) {
                if (c == x) {
                    ans.push_back(i);
                    break;
                }
            }
            ++i;
        }
        return ans;
    }
};
