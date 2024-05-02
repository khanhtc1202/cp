/*
https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        uint8_t seen[1001]={0};
        int k=-1;
        for(int x:nums){
            if (x<0) {
                x=-x;
                seen[x]|=2;
            }
            else seen[x]|=1;
            if (seen[x]==3 && x>k) k=x;
        }
        return k;
    }
};
