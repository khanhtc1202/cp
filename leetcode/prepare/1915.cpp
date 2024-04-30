/*
https://leetcode.com/problems/number-of-wonderful-substrings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int val = 0;
        vector<int> cnt(1024);
        cnt[0] = 1;

        long long ans = 0;
        for (char &c : word) {
            val ^= 1 << (c - 'a');
            ans += cnt[val];
            for (int i = 0; i < 10; i++){
                ans += cnt[val ^ (1 << i)];
            }

            cnt[val]++;
        }

        return ans;
    }
};
