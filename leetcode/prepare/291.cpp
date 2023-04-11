/*
https://leetcode.com/problems/word-pattern-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        int sp = pattern.size(), ss = s.size();
        if (sp == 1) return true;

        unordered_set<string> dict;
        unordered_map<char, string> mapped;

        function<bool(int, int)> backtrack = [&](int i, int j) -> bool {
            if (i == sp && j == ss)
                return true;

            if (i >= sp || j >= ss)
                return false;

            // Current rune in pattern is not visited before
            if (mapped.find(pattern[i]) == mapped.end()) {
                for (int len = 1; len <= ss - j; len++) {
                    string tmp = s.substr(j, len);
                    if (dict.find(tmp) == dict.end()) {
                        dict.insert(tmp);
                        mapped[pattern[i]] = tmp;

                        if (backtrack(i+1, j+len))
                            return true;

                        dict.erase(tmp);
                        mapped.erase(pattern[i]);
                    }
                }
            }
            // If substring start from j is equal to the current mapped string of pattern[i]
            else if (s.substr(j, mapped[pattern[i]].size()) == mapped[pattern[i]])
                return backtrack(i+1, j + mapped[pattern[i]].size());

            return false;
        };

        return backtrack(0, 0);
    }
};
