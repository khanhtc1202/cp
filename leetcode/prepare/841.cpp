/*
https://leetcode.com/problems/keys-and-rooms/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        function<void(int)> dfs = [&](int r) -> void {
            if (visited.find(r) != visited.end()) return;

            visited.insert(r);
            for (auto k: rooms[r]) {
                dfs(k);
            }
        };

        dfs(0);
        return visited.size() == rooms.size();
    }
};
