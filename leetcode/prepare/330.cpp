/*
https://leetcode.com/problems/patching-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long cover = 0;
        int add = 0, sz = nums.size();
        
        for(int i = 0; cover < n; ){
            if (i < sz && cover+1 >= nums[i])
                cover += nums[i++];
            else{
                add++;
                int patch = cover+1;
                cover += patch;
            }
        }
        return add;
    }
};
