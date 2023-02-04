#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = (int)pow(M_E, 0.5 * log(x));
        int right = left + 1;
        return (long)right * right > x ? left : right;
    }
};
