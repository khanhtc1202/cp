/*
https://leetcode.com/problems/letter-tile-possibilities/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> sequences;
        vector<bool> used(tiles.size(), false);

        function<void(string)> backtrack = [&](string curr) {
            sequences.insert(curr);
            for (int pos = 0; pos < tiles.size(); ++pos) {
                if (!used[pos]) {
                    used[pos] = true;
                    backtrack(curr + tiles[pos]);
                    used[pos] = false;
                }
            }
        };

        backtrack("");
        return sequences.size() - 1; // remove "" from sequences
    }
};
