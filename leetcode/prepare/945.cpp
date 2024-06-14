/*
https://leetcode.com/problems/minimum-increment-to-make-array-unique/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        auto [min, max] = minmax_element(nums.begin(), nums.end()); 
        const int n = nums.size(), x0 = *min, M = *max;
        vector<int> freq(M-x0+n+1, 0);
        for(int x: nums)
            freq[x-x0]++;
         
        int cnt = 0, inc = 0;
        for(int x = 0; cnt < n; ++x){
            int f = freq[x];
            cnt += (f!=0);
            if (f <= 1) continue; // No element
            // Update (f-1) element x -> x+1
            freq[x+1] += (f-1);
            inc += (f-1);
        }
        return inc;
    }
};
