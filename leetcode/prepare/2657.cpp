/*
https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n), freq(n+1, 0);

        int count = 0;
        for (int i = 0; i < n; ++i) {
            // If we met the A[i] before, then add 1 to common prefix
            if (++freq[A[i]] == 2) ++count;
            // If we met the B[i] before, then add 1 to common prefix
            if (++freq[B[i]] == 2) ++count;
            // Add the common prefix at index i to ans
            ans[i] = count;
        }
        return ans;
    }
};
