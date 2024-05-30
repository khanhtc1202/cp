/*
https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> pref(arr.begin(), arr.end());
        pref.insert(pref.begin(), 0);
        int N = pref.size();

        for (int i = 1; i < N; ++i) pref[i] ^= pref[i-1];

        int count = 0;
        for (int s = 0; s < N; ++s) {
            for (int e = s+1; e < N; ++e) {
                if (pref[s] == pref[e])
                    count += e-s-1;
            }
        }
        return count;
    }
};
