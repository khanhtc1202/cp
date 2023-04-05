/*
https://leetcode.com/problems/course-schedule-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        for (auto edge: prerequisites) {
            indegree[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> zero_indegree;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) zero_indegree.push(i);
        }
        
        vector<int> res;
        while (!zero_indegree.empty()) {
            int curr = zero_indegree.front(); zero_indegree.pop();
            res.push_back(curr);
            for (auto nei: adj[curr]) {
                indegree[nei]--;
                if (!indegree[nei]) zero_indegree.push(nei);
            }
        }
        if (res.size() != numCourses) return {};
        return res;
    }
};
