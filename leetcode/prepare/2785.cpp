/*
https://leetcode.com/problems/sort-vowels-in-a-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'o'
            || c == 'A' || c == 'E' || c == 'U' || c == 'I' || c == 'O';
    }

    string sortVowels(string s) {
        int freq[200] = {0};
        for (char c: s)
            if (isVowel(c))
                freq[c]++;

        string sortedVowels = "AEIOUaeiou";
        string ans;
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (!isVowel(s[i]))
                ans += s[i];
            else {
                // Skip all placed vowels
                while (freq[sortedVowels[j]] == 0) {
                    j++;
                }

                ans += sortedVowels[j];
                freq[sortedVowels[j]]--;
            }
        }
        return ans;
    }
};
