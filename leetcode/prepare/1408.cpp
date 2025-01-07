/*
https://leetcode.com/problems/string-matching-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i == j) continue;

                if (isSubstringOf(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break; // no need to check further for this word
                }
            }
        }
        return ans;
    }

private:
    bool isSubstringOf(string &sub, string &main) {
        for (int startIndex = 0; startIndex < main.size(); startIndex++) {
            bool subFits = true;

            for (int subIndex = 0; subIndex < sub.size(); subIndex++) {
                if (startIndex + subIndex >= main.size() ||
                    main[startIndex + subIndex] != sub[subIndex]) {
                    subFits = false;
                    break;
                }
            }

            if (subFits) {
                return true;
            }
        }

        return false;
    }
};
