/*
https://leetcode.com/problems/longest-harmonious-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> hash;
        int ans = 0;
        for (int x: nums) {
            hash[x]++;
            if (hash.count(x+1) > 0) ans = max(ans, hash[x+1]+hash[x]);
            if (hash.count(x-1) > 0) ans = max(ans, hash[x-1]+hash[x]);
        }
        return ans;
    }
};
