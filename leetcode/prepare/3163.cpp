/*
https://leetcode.com/problems/string-compression-iii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt = 1; char last_char = word[0];
        for (int i = 1; i < word.size(); ++i) {
            if (word[i] == word[i-1]) {
                cnt++;
                if (cnt == 10) {
                    comp += "9";
                    comp += last_char;
                    cnt = 1;
                }
            } else {
                comp += (cnt+'0');
                comp += last_char;
                last_char = word[i];
                cnt = 1;
            }
        }
        comp += (cnt+'0');
        comp += last_char;
        return comp;
    }
};
