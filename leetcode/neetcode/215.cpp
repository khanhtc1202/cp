/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        function<int(int, int)> quickselect = [&](int l, int r) -> int {
            int pivot = nums[r];
            int p = l;
            for (int i = l; i < r; i++) {
                if (nums[i] <= pivot) {
                    swap(nums[i], nums[p]);
                    p++;
                }
            }
            swap(nums[r], nums[p]);
            
            if (p > k) return quickselect(l, p-1);
            else if (p < k) return quickselect(p+1, r);
            else return nums[p];
        };
        
        return quickselect(0, n-1);
    }
};
