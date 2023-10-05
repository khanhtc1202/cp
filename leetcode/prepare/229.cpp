/*
https://leetcode.com/problems/majority-element-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;
        for (auto num: nums) {
            if (num == cand1) cnt1++;
            else if (num == cand2) cnt2++;
            else if (cnt1 == 0) cand1 = num, cnt1 = 1;
            else if (cnt2 == 0) cand2 = num, cnt2 = 1;
            else cnt1--, cnt2--;
        }

        cnt1 = cnt2 = 0;
        for (auto num: nums) {
            if (num == cand1) cnt1++;
            else if (num == cand2) cnt2++;
        }

        vector<int> ans;
        if (cnt1 > nums.size()/3) ans.push_back(cand1);
        if (cnt2 > nums.size()/3) ans.push_back(cand2);

        return ans;
    }
};
