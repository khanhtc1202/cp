#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edges;
        for (auto& row: wall) {
            int idx = 0;
            for (int i = 0; i < row.size(); i++) {
                idx += row[i];
                if (i != row.size()-1)
                    edges[idx]++;
            }
        }
        int pass = 0;
        for (auto [k, v]: edges) {
            pass = max(pass, v);
        }
        return wall.size() - pass;
    }
};
