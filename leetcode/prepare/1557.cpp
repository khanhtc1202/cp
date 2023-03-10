/*
https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n, false);
        vector<int> ans;
        for (auto edge: edges)
            seen[edge[1]] = true;
        for (int i = 0; i < n; i++)
            if (!seen[i]) ans.push_back(i);
        return ans;
    }
};
