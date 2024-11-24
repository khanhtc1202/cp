/*
https://leetcode.com/problems/separate-black-and-white-balls/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int N = s.size();
        int cnt = 0;
        for (int i = N-1; i > -1; --i) {
            if (s[i] == '0') cnt++;
            else ans += cnt;
        }
        return ans;
    }
};
