/*
https://leetcode.com/problems/course-schedule/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (auto edge: prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        unordered_set<int> visited;
        function<bool(int)> dfs = [&](int src) -> bool {
            if (visited.find(src) != visited.end()) return false;
            if (graph[src].size() == 0) return true;

            visited.insert(src);
            for (auto pre: graph[src]) {
                if (!dfs(pre)) return false;
            }
            visited.erase(src);
            graph[src].clear();
            return true;
        };
        
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }
        
        return true;
    }
};
