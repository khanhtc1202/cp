/*
https://leetcode.com/problems/number-of-provinces/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> provinces(n, 0);
        auto bfs = [&](int c, int p) -> void {
            queue<int> q;
            q.push(c);
            provinces[c] = p;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v = 0; v < n; v++) {
                    if (isConnected[u][v] == 0) continue;
                    if (provinces[v] != 0) continue;

                    q.push(v);
                    provinces[v] = p;
                }
            }
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (provinces[i] == 0)
                bfs(i, ++ans);
        }
        return ans;
    }
};
