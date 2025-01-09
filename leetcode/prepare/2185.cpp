/*
https://leetcode.com/problems/counting-words-with-a-given-prefix/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (string& s: words) {
            if (s.find(pref) == 0) ans++;
        }
        return ans;
    }
};
