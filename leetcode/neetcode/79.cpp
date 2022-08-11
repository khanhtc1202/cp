#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        int sz = word.size();

        // follow up
        if (sz > m*n) return false;
        // another thing to do is counting all chars in board and return
        // false if board does not contain enough char for word.
        // I don't do it here :)

        auto valid = [&](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        string tmp = ""; bool res = false;

        function<void(int, int, int)> backtrack = [&](int x, int y, int idx) -> void {
            if (idx == sz) {
                res = true;
                return;
            }

            for (int i = 0; i < dx.size(); i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (!valid(nx, ny) || board[nx][ny] != word[idx])
                    continue;

                tmp.push_back(word[idx]); board[nx][ny] = 0;
                backtrack(nx, ny, idx+1);
                tmp.pop_back(); board[nx][ny] = word[idx];
            }
        };

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    tmp = word[0];
                    board[i][j] = 0;
                    backtrack(i, j, 1);
                    board[i][j] = word[0];
                }
                if (res) return true;
            }
        return false;
    }
};
