#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string out = "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (auto str: strs) {
                if (str.size() < i+1)
                    return out;
                if (str[i] != strs[0][i])
                    return out;
            }
            out += strs[0][i];
        }
        return out;
    }
};
