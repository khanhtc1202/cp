/*
https://leetcode.com/problems/possible-bipartition/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < dislikes.size(); i++) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> group(n+1, 0);
        for (int i = 1; i <= n; i++) {
            if (group[i] != 0) continue;

            vector<int> stk;
            stk.push_back(i);
            group[i] = 1;
            while (!stk.empty()) {
                int u = stk.back(); stk.pop_back();
                for (auto v: adj[u]) {
                    if (group[v] == 0) {
                        group[v] = -group[u];
                        stk.push_back(v);
                    }
                    if (group[v] == group[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
