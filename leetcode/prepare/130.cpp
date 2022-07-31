#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<pair<int, int>> save;

        bool border;
        vector<pair<int, int>> tmp;
        function<void(int, int)> flip = [&](int i, int j) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == 'X')
                return;
            if (i == 0 || i == n-1 || j == 0 || j == m-1)
                border = true;
            board[i][j] = 'X';
            tmp.push_back({i,j});
            flip(i-1, j);
            flip(i+1, j);
            flip(i, j-1);
            flip(i, j+1);
        };

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    border = false; tmp.clear();
                    flip(i, j);
                    if (border)
                        for (auto p: tmp)
                            save.push_back(p);
                }
            }

        for (auto p: save)
            board[p.first][p.second] = 'O';
    }
};
