/*
https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0;
        for (int i = 1; i < colors.size()-1; ++i) {
            if (colors[i-1] != colors[i] || colors[i] != colors[i+1])
                continue;

            if (colors[i] == 'A') alice++;
            else bob++;
        }
        return alice > bob;
    }
};
