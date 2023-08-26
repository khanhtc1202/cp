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
        for (const auto& p: pairs) {
            pair<int, int> last = make_pair(0, -1e4);
            for (const auto& prev: dp) {
                if (p[0] > prev.second) {
                    last = max(last, make_pair(prev.first+1, p[1]));
                }
            }
            dp.push_back(last);
        }
        return max_element(dp.begin(), dp.end())->first;
    }

    int findLongestChain_Greedy(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int curr = INT_MIN, ans = 0;
        for (const auto& p: pairs) {
            if (p[0] > curr) {
                ans++;
                curr = p[1];
            }
        }
        return ans;
    }
};
