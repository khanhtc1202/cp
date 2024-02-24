/*
https://leetcode.com/problems/find-all-people-with-secret/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for (auto& mtg: meetings) {
            int x = mtg[0], y = mtg[1], t = mtg[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }

        // earliest stores earliest time a person learns about the secret,
        // we need to update all others people who met updated person after the
        // time he/she learn about the secret
        vector<int> earliest(n, INT_MAX);
        // 0 and firstPerson know first
        earliest[0] = 0; earliest[firstPerson] = 0;

        // DFS
        dfs(0, 0, graph, earliest);
        dfs(firstPerson, 0, graph, earliest);

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (earliest[i] != INT_MAX) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    void dfs(int person, int time, auto& graph, auto& earliest) {
        for (auto [t, nextPerson]: graph[person]) {
            if (t >= time && earliest[nextPerson] > t) {
                earliest[nextPerson] = t;
                dfs(nextPerson, t, graph, earliest);
            }
        }
    }
};
