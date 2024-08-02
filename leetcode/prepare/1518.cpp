/*
https://leetcode.com/problems/water-bottles/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int n, int k) {
        return n+(n-1)/(k-1);
    }
};
