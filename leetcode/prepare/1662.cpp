/*
https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual_Hard(vector<string>& word1, vector<string>& word2) {
        int j1 = word1[0].size(), j2 = word2[0].size();
        int len1 = j1, len2 = j2;
        int k1 = 0, k2 = 0, count = 0;

        for (int i1 = 0, i2 = 0; i1 < word1.size() && i2 < word2.size(); ++count) {
            if (word1[i1][k1] != word2[i2][k2])
                return false;

            k1++; k2++;
            // word1[i1] run out
            if (k1 == j1) {
                // move to next word in word1
                k1 = 0, i1++;
                // update accumulate count len1 by adding word1[i1] size
                j1 = (i1 < word1.size()) ? word1[i1].size() : 0;
                len1 += j1;
            }

            // same with word2[i2]
            if (k2 == j2) {
                k2 = 0, i2++;
                j2 = (i2 < word2.size()) ? word2[i2].size() : 0;
                len2 += j2;
            }
        }
        return count == len1 && count == len2;
    }

    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        string s2 = "";

        for(const string& s : word1)
            s1 += s;
        for(const string& s : word2)
            s2 += s;

        return s1==s2;
    }
};
