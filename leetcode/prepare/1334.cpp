/*
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e6+1));
        
        for (auto e: edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = dist[v][u] = w;
        }
        
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        for (int k = 0; k < n; k++)
            for (int u = 0; u < n; u++)
                for (int v = 0; v < n; v++) {
                    if (dist[u][k] + dist[k][v] < dist[u][v]) {
                        dist[u][v] = dist[u][k] + dist[k][v];
                    }
                }
        
        int ans = 0, cmin = n+1;
        for (int u = 0; u < n; u++) {
            int cnt = 0;
            for (int v = 0; v < n; v++) {
                if (dist[u][v] <= distanceThreshold) cnt++;
            }
            if (cmin >= cnt) {
                ans = u;
                cmin = cnt;
            }
        }
        return ans;
    }
};
