#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            vector<string> pair = equations[i];
            graph[pair[0]][pair[1]] = values[i];
            graph[pair[1]][pair[0]] = 1 / values[i];
        }
        
        auto bfs = [&](string s, string t) -> double {
            unordered_map<string, string> path;
            queue<string> q;
            q.push(s);
            while (!q.empty()) {
                string curr = q.front(); q.pop();
                for (auto nei: graph[curr]) {
                    if (path.find(nei.first) != path.end())
                        continue;
                    path[nei.first] = curr;
                    q.push(nei.first);
                    // stop early
                    if (nei.first == t) break;
                }
            }
            if (path.find(t) == path.end())
                return -1;
            double ans = 1;
            string curr = t;
            while (curr != s) {
                ans *= graph[path[curr]][curr];
                curr = path[curr];
            }
            return ans;
        };
        
        vector<double> res;
        for (auto pair: queries) {
            if (graph.find(pair[0]) == graph.end() || graph.find(pair[1]) == graph.end())
                res.push_back(-1);
            else if (pair[0] == pair[1])
                res.push_back(1);
            else
                res.push_back(bfs(pair[0], pair[1]));
        }
        return res;
    }
};
