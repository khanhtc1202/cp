/*
https://leetcode.com/problems/maximum-length-of-pair-chain/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<pair<int, int>> dp;
        dp.push_back(make_pair(0, -1e4));
        for (auto p: pairs) {
            pair<int, int> last = make_pair(0, -1e4);
            for (auto prev: dp) {
                if (p[0] > prev.second) {
                    last = max(last, make_pair(prev.first+1, p[1]));
                }
            }
            dp.push_back(last);
        }
        return max_element(dp.begin(), dp.end())->first;
    }
};
