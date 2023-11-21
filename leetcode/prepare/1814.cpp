/*
https://leetcode.com/problems/count-nice-pairs-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
const int MOD = 1e9+7;
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> memo;
        int ans = 0;
        for (int x: nums) {
            int sub = x - rev(x);
            if (memo.find(sub) != memo.end()) {
                (ans += memo[sub]) %= MOD;
            }
            memo[sub]++;
        }
        return ans;
    }

    int rev(int num) { 
        int rev_num = 0; 
        while (num > 0) { 
            rev_num = rev_num * 10 + num % 10; 
            num = num / 10; 
        } 
        return rev_num; 
    }
};
