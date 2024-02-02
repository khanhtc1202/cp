/*
https://leetcode.com/problems/sequential-digits/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string digits = "123456789";
        int llen = to_string(low).size();
        int hlen = to_string(high).size();

        for (int i = llen; i <= hlen; ++i) {
            int l = 0, r = i;
            while (r <= 9) { // digits size
                int num = stoi(digits.substr(l, r-l));
                if (num >= low && num <= high) ans.push_back(num);
                l++; r++;
                if (num > high) break;
            }
        }
        return ans;
    }
};
