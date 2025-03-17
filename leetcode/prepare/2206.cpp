/*
https://leetcode.com/problems/divide-array-into-equal-pairs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        bitset<501> bs;
        for (const int x: nums) bs.flip(x);
        return bs.none();
    }
};
