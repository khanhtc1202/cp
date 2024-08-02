/*
https://leetcode.com/problems/pass-the-pillow/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int foo = time / (n-1);
        int bar = time % (n-1);
        if (foo % 2) return n - bar;
        else return bar+1;
    }
};
