/*
https://leetcode.com/problems/bitwise-xor-of-all-pairings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();

        unordered_map<int, long> freq;
        for (int x: nums1) freq[x] += l2;
        for (int x: nums2) freq[x] += l1;

        int ans = 0;
        for (auto& [num, count]: freq) {
            if (count % 2)
                ans ^= num;
        }
        return ans;
    }
};
