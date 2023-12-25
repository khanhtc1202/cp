/*
https://leetcode.com/problems/minimum-cost-to-convert-string-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));
        for (int i = 0; i < original.size(); ++i) {
            int s = original[i] - 'a', t = changed[i] - 'a';
            dist[s][t] = dist[s][t] == 0 ? cost[i] : min(dist[s][t], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) continue;
            int s = source[i] - 'a', t = target[i] - 'a';
            if (dist[s][t] >= INT_MAX) return -1;
            ans += dist[s][t];
        }
        return ans;
    }
};
