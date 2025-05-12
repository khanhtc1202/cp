/*
https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int T[7] = {0}, B[7] = {0}, S[7] = {0}; // S[7] count domino which T==B
        for (int i = 0; i < n; ++i) {
            T[tops[i]]++;
            B[bottoms[i]]++;
            S[tops[i]] += (tops[i]==bottoms[i]);
        }
        int ans = INT_MAX;
        for (int x = 1; x < 7; ++x) {
            if (T[x]+B[x]-S[x] == n) { // only valid number
                ans = min(ans, min(n-T[x], n-B[x]));
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
