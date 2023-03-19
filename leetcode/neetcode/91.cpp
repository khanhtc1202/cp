/*
https://leetcode.com/problems/decode-ways/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecoding(string s) {
        vector<int> res(s.size()+1, 0);
        res[0] = 1;

        int c = s[0] - '0';
        if (c == 0)
            return 0;
        res[1] = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] - '0' > 0)
                res[i+1] += res[i];
            if (s[i-1] != '0' && stoi(s.substr(i-1, 2)) < 27)
                res[i+1] += res[i-1];
            if (s[i-1] == s[i] == '0')
                return 0;
        }
        return res[s.size()];
    }

    int numDecodingOps(string s) {
        if (s[0] == '0')
            return 0;

        int prev2 = 1;
        int prev1 = 1;
        int res;
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == s[i] == '0')
                return 0;

            res = 0;
            if (s[i] - '0' > 0)
                res += prev1;
            if (s[i-1] != '0' && stoi(s.substr(i-1, 2)) < 27)
                res += prev2;
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
};
