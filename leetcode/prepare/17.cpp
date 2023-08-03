/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string s;
        vector<string> ans;
        vector<string> input = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        function<void(int, string&)> backtrack = [&](int i, string& d) {
            if (i == d.size()) {
                ans.push_back(s);
                return;
            }

            for (auto c : input[d[i] - '0']) {
                s += c;
                backtrack(i+1, d);
                s.pop_back();
            }
        };

        if (digits.size() == 0) {
            return ans;
        }
        backtrack(0, digits);
        return ans;
    }

    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinationsStraight(string digits) {
        if (digits.empty()) return {};
		vector<string> result;
        result.push_back("");
        
        for(auto digit: digits) {
            vector<string> tmp;
            for(auto candidate: pad[digit - '0']) {
                for(auto s: result) {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};
