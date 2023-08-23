/*
https://leetcode.com/problems/reorganize-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<pair<int,char>> freq(26, {0, ' '});
        for (auto c: s) {
            freq[c-'a'].first++;
            freq[c-'a'].second = c;
        }

        int max_freq = 0, max_i = -1;
        for (int i = 0; i < 26; ++i) {
            if (max_freq < freq[i].first) {
                max_freq = freq[i].first;
                max_i = i; // Get the char.
            }
        }

        // If there is more char c than half of s size, no way to rearrangement
        if (max_freq > (n+1)/2) return "";

        // Push max_freq char to top of budget and build the string s
        swap(freq[0], freq[max_i]);
        string ans(n, 'X');

        int j = 0; // index run on freq budget
        for (int i = 0; i < n; i += 2) {
            // Skip empty char (freq = 0)
            while (j < 26 && freq[j].first == 0) ++j;
            ans[i] = freq[j].second;
            freq[j].first--;
        }

        for (int i = 1; i < n; i += 2) {
            // Skip empty char
            while (j < 26 && freq[j].first == 0) ++j;
            ans[i] = freq[j].second;
            freq[j].first--;
        }

        return ans;
    }
};
