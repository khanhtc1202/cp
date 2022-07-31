#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int INF = INT32_MAX;

    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size(), m = rooms[0].size();
        queue<pair<int, int>> qrooms;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (rooms[i][j] == 0)
                    qrooms.push({i,j});

        auto validRoom = [=](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        pair<int, int> u;
        while (!qrooms.empty()) {
            u = qrooms.front();
            qrooms.pop();
            for (int i = 0; i < dx.size(); i++) {
                int vx = u.first + dx[i];
                int vy = u.second + dy[i];

                if (!validRoom(vx, vy)) continue;
                if (rooms[vx][vy] != INF) continue; // hit the wall or already visited room so stop.

                qrooms.push({vx, vy});
                rooms[vx][vy] = rooms[u.first][u.second];
            }
        }
    }
};

int main() {
    Solution sol;
    cout << sol.INF << endl;
}
