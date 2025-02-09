/*
https://leetcode.com/problems/count-number-of-bad-pairs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> diffCount;
        long long badPairs = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = nums[i] - i;
            int goodPairs = diffCount[diff]; // good pairs is nums[i] - i == nmums[j] - j
            badPairs += i - goodPairs; // number of pairs created by new (nums[i] - i) with previous pair
            diffCount[diff] = goodPairs + 1;
        }
        return badPairs;
    }
};
