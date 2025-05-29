/*
https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int node, int parent, int depth, const vector<vector<int>>& children, vector<int>& color) {
        int res = 1 - depth % 2;
        color[node] = depth % 2; // 0 or 1
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, depth+1, children, color);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, vector<int>& color) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const auto& e: edges) {
            children[e[0]].push_back(e[1]);
            children[e[1]].push_back(e[0]);
        }

        int res = dfs(0, -1, 0, children, color);
        // res is number of node with same color with root
        // while n-res is number of node with the other color with root
        return {res, n - res};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> color1(n);
        vector<int> color2(m);
        vector<int> count1 = build(edges1, color1);
        vector<int> count2 = build(edges2, color2);
        int maxColor2 = max(count2[0], count2[1]);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = count1[color1[i]] + maxColor2;
        }
        return ans;
    }
};
