/*
https://leetcode.com/problems/shortest-path-to-get-all-keys/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        unordered_map<char, int> key_bit;
        int bit_start = 0;
        vector<int> start;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (islower(grid[i][j]))
                    key_bit[grid[i][j]] = bit_start++;

                if (grid[i][j] == '@')
                    start = {i, j, 0}; // no key state
            }

        int state_end = (1 << bit_start) - 1;
        int state_size = (1 << bit_start);

        vector<vector<vector<bool>>> seen(m, vector<vector<bool>>(n, vector<bool>(state_size, false)));

        queue<vector<int>> q;
        q.push(start);
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                int row = q.front()[0];
                int col = q.front()[1];
                int state = q.front()[2];
                q.pop();

                if (row < 0 || row >= m || col < 0 || col >= n) continue;
                if (grid[row][col] == '#') continue;
                if (seen[row][col][state]) continue;

                // Faced lock
                if (isupper(grid[row][col])) {
                    // But no required key collected
                    if ((state & (1 << key_bit[tolower(grid[row][col])])) == 0)
                        continue;
                }

                // Faced key, then pick it
                if (islower(grid[row][col])) {
                    state = state | (1 << key_bit[grid[row][col]]);
                }
                // Check key collection right after collect a key
                if (state == state_end) return ans;

                seen[row][col][state] = true;

                // visit around
                q.push({row+1, col, state});
                q.push({row-1, col, state});
                q.push({row, col+1, state});
                q.push({row, col-1, state});
            }
            // Spill around
            ans++;
        }
        return -1;
    }
};
