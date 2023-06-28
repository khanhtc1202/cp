/*
https://leetcode.com/problems/path-with-maximum-probability/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            auto e = edges[i];
            adj[e[0]].push_back(make_pair(e[1], succProb[i]));
            adj[e[1]].push_back(make_pair(e[0], succProb[i]));
        }

        vector<double> prob(n, 0.0);
        prob[start] = 1.0;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto [v, p]: adj[u]) {
                double newProb = prob[u] * p;
                if (newProb > prob[v]) {
                    prob[v] = newProb;
                    q.push(v);
                }
            }
        }

        return prob[end];
    }
};
