/*
https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ans = arr[0], cnt = 0, prev = 0;
        for (int i = 1; i < arr.size(); ++i) {
            cnt = (arr[i] == arr[i-1]) ? cnt + 1 : 1;
            if (cnt > prev)
                ans = arr[i], prev = cnt;
        }
        return ans;
    }
};
