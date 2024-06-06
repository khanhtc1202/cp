/*
https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        map<int, int> freq;
        for (auto x: nums) freq[x]++;

        while (!freq.empty()) {
            int curr = freq.begin()->first;
            for (int i = 0; i < k; ++i) {
                int need = curr+i;
                if (freq.find(need) == freq.end()) return false;
                freq[need]--;
                if (freq[need] == 0) freq.erase(need);
            }
        }
        return true;
    }
};
