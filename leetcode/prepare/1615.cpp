/*
https://leetcode.com/problems/maximal-network-rank/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int adj[101][101] = {};
        int rank[101] = {};
        for (auto& road: roads) {
            adj[road[0]][road[1]] = 1;
            adj[road[1]][road[0]] = 1;
            rank[road[0]]++;
            rank[road[1]]++;
        }
        
        int ans = 0;
        for (int u = 0; u < n; ++u) {
            for (int v = u+1; v < n; ++v) {
                ans = max(ans, rank[u] + rank[v] - (adj[u][v] == 1));
            }
        }
        return ans;
    }
};
