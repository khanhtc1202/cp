#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> sums;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                sums[nums1[i]+nums2[j]]++;
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                ans += sums[-(nums3[i]+nums4[j])];
            }
        return ans;
    }
};
