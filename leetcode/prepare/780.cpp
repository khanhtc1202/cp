/*
https://leetcode.com/problems/reaching-points/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if ((sx == sy) && (tx == ty)) return sx == tx;

        while (tx > sx && ty > sy) {
            if (tx > ty) tx = tx % ty;
            else ty = ty % tx;
        }
        if (tx < sx || ty < sy) return false;
        if (tx == sx) return (ty - sy) % sx == 0;
        if (ty == sy) return (tx - sx) % sy == 0;
        return false;
    }
};
