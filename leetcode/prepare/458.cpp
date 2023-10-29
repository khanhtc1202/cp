/*
https://leetcode.com/problems/poor-pigs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int poorPigs_Log(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log2(buckets)/log2(int(minutesToTest/minutesToDie)+1));
    }

    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        signed x = 0, B = minutesToTest/minutesToDie + 1, T = 1;
        for (; T < buckets; ++x) T*=B;
        return x;
    }
};
