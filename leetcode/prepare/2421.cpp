/*
Problem desc: https://leetcode.com/problems/number-of-good-paths/
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, emax, ecount;
    int n;

    DSU(vector<int>& vals): n(vals.size()) {
        parent.resize(n, 0);
        ecount.resize(n, 1);
        emax = vals;

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findSet(int u) {
        if (parent[u] != u) {
            parent[u] = findSet(parent[u]);
        }
        return parent[u];
    }

    int unionSet(int u, int v) {
        int up = findSet(u);
        int vp = findSet(v);

        int ans = 0;
        if (up == vp)
            return ans;

        if (emax[up] == emax[vp]) {
            parent[up] = vp;
            ans = ecount[up] * ecount[vp];
            ecount[vp] += ecount[up];
            return ans;
        }

        if (emax[up] > emax[vp]) {
            swap(up, vp);
        }
        parent[up] = vp;
        return 0;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n, vector<int>());
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vertexes(n, 0);
        for (int i = 0; i < n; i++)
            vertexes[i] = i;

        sort(vertexes.begin(), vertexes.end(), [&](int x, int y) {
            return vals[x] < vals[y];
        });

        DSU dsu(vals);
        int ans = n;
        for (auto v: vertexes) {
            for (auto nei: adj[v]) {
                if (vals[nei] <= vals[v]) {
                    ans += dsu.unionSet(nei, v);
                }
            }
        }
        return ans;
    }
};
