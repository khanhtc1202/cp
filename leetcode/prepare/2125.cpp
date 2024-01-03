/*
https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDevices(string& s) {
        int dev = 0;
        for (auto c: s) if (c == '1') dev++;
        return dev;
    }

    int numberOfBeams(vector<string>& bank) {
        if (bank.size() == 1) return 0;

        int ans = 0;
        int prev = countDevices(bank[0]);
        for (int i = 1; i < bank.size(); ++i) {
            int curr = countDevices(bank[i]);
            if (curr == 0) continue;
            ans += curr*prev;
            prev = curr;
        }
        return ans;
    }
};
