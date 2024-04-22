/*
https://leetcode.com/problems/open-the-lock/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Map the next slot digit for each current slot digit.
        unordered_map<char, char> nextSlot = {
            {'0', '1'}, 
            {'1', '2'}, 
            {'2', '3'}, 
            {'3', '4'}, 
            {'4', '5'},
            {'5', '6'}, 
            {'6', '7'}, 
            {'7', '8'}, 
            {'8', '9'}, 
            {'9', '0'}
        };
        // Map the previous slot digit for each current slot digit.
        unordered_map<char, char> prevSlot = {
            {'0', '9'}, 
            {'1', '0'}, 
            {'2', '1'}, 
            {'3', '2'}, 
            {'4', '3'},
            {'5', '4'}, 
            {'6', '5'}, 
            {'7', '6'}, 
            {'8', '7'}, 
            {'9', '8'}
        };

        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> q;
        int ans = 0;

        if (visited.count("0000")) return -1; // "0000" is in deadends

        q.push("0000");
        visited.insert("0000");
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string state = q.front(); q.pop();
                if (state == target) return ans;

                // Visit all neighbors of current state
                // There are 4x2 neighbors like that
                for (int j = 0; j < 4; ++j) {
                    // Rotate to the next slot
                    string next = state;
                    next[j] = nextSlot[next[j]];
                    // Found new combination state
                    if (visited.count(next) == 0) {
                        q.push(next);
                        visited.insert(next);
                    }
                    // Rotate to the prev slot
                    string prev = state;
                    prev[j] = prevSlot[prev[j]];
                    // Found new combination state
                    if (visited.count(prev) == 0) {
                        q.push(prev);
                        visited.insert(prev);
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
