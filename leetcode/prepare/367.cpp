#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        int l = 1, r = num/2;
        while (l <= r) {
            double m = l + (r-l)/2;
            double sq = m*m;
            if (sq < num) {
                l = m+1;
                continue;
            }
            
            if (sq > num) {
                r = m-1;
                continue;
            }
            
            return true;
        }
        return l == r;
    }
};
