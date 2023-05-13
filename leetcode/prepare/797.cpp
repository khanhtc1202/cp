/*
https://leetcode.com/problems/all-paths-from-source-to-target/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        
        function<void(int)> travel = [&](int u) {
            path.push_back(u);
            if (u == n-1) {
                ans.push_back(path);
            }

            for (auto nei: graph[u]) {
                travel(nei);
            }
            path.pop_back();
        };

        travel(0);
        return ans;
    }
};
