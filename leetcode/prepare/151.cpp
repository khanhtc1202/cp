/*
https://leetcode.com/problems/reverse-words-in-a-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans;
        while (ss >> word) {
            ans = word + " " + ans;
        }
        // Remove last " " which push first
        return ans.substr(0, ans.size()-1);
    }
};
