/*
https://leetcode.com/problems/median-of-two-sorted-arrays/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) {
            return 1.0*(nums2[nums2.size()/2] + nums2[(nums2.size() - 1)/2]) / 2;
        }
        if (nums2.size() == 0) {
            return 1.0*(nums1[nums1.size()/2] + nums1[(nums1.size() - 1)/2]) / 2;
        }
        int total = nums1.size() + nums2.size();
        auto findMedian = [](vector<int>& arr1, vector<int>& arr2) -> int {
            int m = arr1.size(), n = arr2.size();
            int ans = -1;
            int l = 0, r = min(m - 1, (m+n)/2);
            while (l <= r) {
                int mid = (l+r)/2;
                int idx2 = (m+n-1)/2 - mid - 1;
                if ((idx2 == -1) || (idx2 < arr2.size() && arr2[idx2] <= arr1[mid])) {
                    ans = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            return ans;
        };

        int med1 = findMedian(nums1, nums2);
        int med2 = findMedian(nums2, nums1);


        
        if ((nums1.size() + nums2.size()) % 2 != 0) {
            if (med1 == -1) return nums2[med2];
            if (med2 == -1) return nums1[med1];
            return min(nums1[med1], nums2[med2]);
        }


        if (med2 == -1 || (med1 != -1 && nums1[med1] < nums2[med2])) {
            int res = 0;
            if (med1+1 >= nums1.size()) res = nums2[(total - 1) / 2 - med1];
            else if ((total - 1) / 2 - med1 >= nums2.size()) res = nums1[med1+1];
            else res = min(nums1[med1+1], nums2[(total - 1) / 2 - med1]);

            return 1.0*(nums1[med1] + res)/2;
        }

        int res = 0;
        if (med2+1 >= nums2.size()) res = nums1[(total - 1) / 2 - med2];
        else if ((total - 1) / 2 - med2 >= nums1.size()) res = nums2[med2+1];
        else res = min(nums2[med2+1], nums1[(total - 1) / 2 - med2]);

        return 1.0*(nums2[med2] + res)/2;
    }
};
