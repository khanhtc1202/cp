/*
https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int freq[26]={0};
        for(char c: word) 
            freq[c-'a']++;
        sort(begin(freq), end(freq), greater<int>());

        int i = 0;
        return accumulate(freq, freq+26, 0, [&i](int sum, int f) {
            return sum += (f*(i++/8 + 1));
        });
    }
};
