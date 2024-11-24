/*
https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        function<int(int,unordered_set<string>&)> backtrack = [&](int start, unordered_set<string>& seen) -> int {
            if (start == s.size()) return 0;

            int maxCnt = 0;
            for (int end = start+1; end <= s.size(); ++end) {
                string substr = s.substr(start, end - start);
                // Not yet seen before
                if (seen.find(substr) == seen.end()) {
                    seen.insert(substr);
                    maxCnt = max(maxCnt, 1 + backtrack(end, seen));
                    seen.erase(substr);
                }
            }
            return maxCnt;
        };

        return backtrack(0, seen);
    }
};
