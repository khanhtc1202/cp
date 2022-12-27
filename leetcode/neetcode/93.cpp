#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        auto valid = [&](int start, int length) -> bool {
            return length == 1 || (s[start] != '0' && (length < 3 || s.substr(start, length) <= "255"));
        };
        
        vector<string> res;
        vector<int> dots;

        auto buildIP = [&]() -> string {
            string ip;
            int last = 0;
            for (int dot: dots) {
                ip.append(s.substr(last, dot));
                last += dot;
                ip.append(".");
            }
            ip.append(s.substr(last));
            return ip;
        };

        function<void(int)> backtrack = [&](int startIdx) -> void {
            int remainSize = s.size() - startIdx;
            int remainNumbers = 4 - dots.size();

            if (remainSize > remainNumbers * 3 || remainSize < remainNumbers) {
                return;
            }

            // The remain digits to build the last number
            if (dots.size() == 3) {
                if (valid(startIdx, remainSize)) {
                    res.push_back(buildIP());
                }
                return;
            }

            // backtrack
            for (int curPos = 1; curPos <= 3 && curPos <= remainSize; ++curPos) {
                dots.push_back(curPos);
                if (valid(startIdx, curPos)) {
                    backtrack(startIdx + curPos);
                }
                dots.pop_back();
            }
        };

        backtrack(0);
        return res;
    }
};
