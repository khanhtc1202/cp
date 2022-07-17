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

    // bool isValidSudoku(vector<vector<char>>& board) {
    //     for (int i = 0; i < 9; i++) {
    //         if (!isValidRow(board, i) || !isValidCol(board, i))
    //             return false;
    //     }
    //     for (int i = 0; i < 9; i = i+3)
    //         for (int j = 0; j < 9; j = j+3)
    //             if (!isValidBlock(board, {i, j}, {i+2,j+2}));
    //                 return false;

    //     return true;
    // }

    // bool isValidCol(vector<vector<char>>& board, int col) {
    //     unordered_map<char, int> hp;
    //     for (auto& row: board) {
    //         char cur = row[col];
    //         if (cur == '.')
    //             continue;
    //         if (hp.find(cur) != hp.end())
    //             return false;
    //     }
    //     return true;
    // }

    // bool isValidRow(vector<vector<char>>& board, int row) {
    //     unordered_map<char, int> hp;
    //     for (auto& x: board[row]) {
    //         if (x == '.')
    //             continue;
    //         if (hp.find(x) != hp.end())
    //             return false;
    //     }
    //     return true;
    // }

    // bool isValidBlock(vector<vector<char>>& board, pair<int, int> tl, pair<int, int> br) {
    //     unordered_map<char, int> hp;
    //     for (int i = tl.first; i <= br.first; i++)
    //         for (int j = tl.second; j <= br.second; j++) {
    //             char cur = board[i][j];
    //             if (cur == '.')
    //                 continue;
    //             if (hp.find(cur) != hp.end())
    //                 return false;
    //             hp[cur] = 1;
    //         }

    //     return true;
    // }
};
