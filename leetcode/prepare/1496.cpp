/*
https://leetcode.com/problems/path-crossing/
*/
#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
struct PairHash {
    size_t operator()(ii const& s) const {
        size_t h1 = hash<int>{}(s.first);
        size_t h2 = hash<int>{}(s.second);
        return h1 ^ (h2 << 15); 
    }
};

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<ii, PairHash> P;
        int x0 =10000, y0=10000;
        P.insert({x0, y0});

        for (char c : path) {
            switch (c) {
                case 'N': y0++; break;
                case 'S': y0--; break;
                case 'E': x0++; break;
                case 'W': x0--; break;
            }
            if (P.count({x0, y0})==1) return true;
            P.insert({x0, y0});
        }
        return false;
    }
};
