/*
https://leetcode.com/problems/destination-city/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> m;
        for (auto& path : paths) {
            m[path[0]]++;
            m[path[1]]++;
        }
        for (auto& path : paths) {
            if (m[path[1]] == 1) return path[1];
        }
        return "";
    }

    string destCity_Set(vector<vector<string>>& paths) {
        unordered_set<string> routes;
        for (auto p: paths) {
            routes.insert(p[0]);
        }
        for (auto p: paths) {
            if (routes.count(p[1]) == 0) return p[1];
        }
        return "";
    }
};
