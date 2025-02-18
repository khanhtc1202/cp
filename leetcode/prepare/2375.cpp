/*
https://leetcode.com/problems/construct-smallest-number-from-di-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        vector<int> stk;
        for (int i = 0; i <= pattern.size(); ++i) {
            // delay the time to add current number by push to the stack
            stk.push_back(i+1);
            // If the next number must be increase or it's the end of pattern
            // Build the string based on delayed number in stack
            if (pattern.size() == i || pattern[i] == 'I') {
                while (!stk.empty()) {
                    ans += to_string(stk.back());
                    stk.pop_back();
                }
            }
        }
        return ans;
    }
};
