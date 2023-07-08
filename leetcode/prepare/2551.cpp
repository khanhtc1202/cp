/*
https://leetcode.com/problems/put-marbles-in-bags/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairWeights(n-1, 0);
        for (int i = 1; i < n; ++i) {
            pairWeights[i-1] = weights[i] + weights[i-1];
        }

        sort(pairWeights.begin(), pairWeights.end());

        long long ans = 0;
        // Ans is the diff between largest k-1 pair and smallest k-1 pair
        // pairWeights size = n-1
        for (int i = 0; i < k-1; ++i) {
            ans += pairWeights[n-2-i] - pairWeights[i];
        }
        return ans;
    }
};
