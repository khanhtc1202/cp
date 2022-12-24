#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<char, int>> rhp(9);
        unordered_map<int, unordered_map<char, int>> chp(9);
        unordered_map<string, unordered_map<char, int>> bhp(9);

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                char cur = board[i][j];
                if (cur == '.')
                    continue;

                string key = makeKey(i/3,j/3);
                if (rhp[i].find(cur) != rhp[i].end() ||
                    chp[j].find(cur) != chp[j].end() ||
                    bhp[key].find(cur) != bhp[key].end())
                    return false;

                rhp[i][cur] = 1;
                chp[j][cur] = 1;
                bhp[key][cur] = 1;
            }
        return true;
    }

    string makeKey(int x, int y) {
        return to_string(x) + to_string(y);
    }
};
