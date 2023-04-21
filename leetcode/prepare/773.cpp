/*
https://leetcode.com/problems/sliding-puzzle/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        auto move = [](vector<vector<int>>& state, int u, int v, int x, int y) {
            swap(state[u][v], state[x][y]);
        };

        const vector<vector<int>> endState = {{1,2,3},{4,5,0}};
        queue<vector<vector<int>>> q;
        q.push(board);
        map<vector<vector<int>>, int> dist;
        dist[board] = 0;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            if (curr == endState) return dist[curr];
            
            int u, v;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 3; j++)
                    if (curr[i][j] == 0) tie(u, v) = {i, j};

            for (int i = 0; i < 4; i++) {
                int x = u + dx[i], y = v + dy[i];
                if (x < 0 || x > 1 || y < 0 || y > 2) continue;
                
                vector<vector<int>> next = curr;
                move(next, u, v, x, y);

                if (dist.count(next)) continue;
                
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
        return -1;
    }
};
