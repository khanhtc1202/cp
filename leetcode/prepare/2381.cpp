/*
https://leetcode.com/problems/shifting-letters-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n, 0);
        for (auto shift: shifts) {
            if (shift[2] == 1) {
                diff[shift[0]]++;
                if (shift[1]+1 < n) {
                    diff[shift[1]+1]--;
                }
            } else {
                diff[shift[0]]--;
                if (shift[1]+1 < n) {
                    diff[shift[1]+1]++;
                }
            }
        }

        string res(n, ' ');
        int numberOfShift = 0;
        for (int i = 0; i < n; ++i) {
            numberOfShift = (numberOfShift + diff[i]) % 26;

            if (numberOfShift < 0) numberOfShift += 26;

            res[i] = 'a' + (s[i] - 'a' + numberOfShift) % 26;
        }

        return res;
    }
};
