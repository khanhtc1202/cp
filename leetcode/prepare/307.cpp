#include <bits/stdc++.h>
using namespace std;

class NumArray {
    int n;
    vector<int> segmentree;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentree.resize(4*n, 0);
        
        function<void(int, int, int)> build = [&](int left, int right, int index) -> void {
            if (left == right) {
                segmentree[index] = nums[left];
                return;
            }
            
            int mid = (right - left) / 2 + left;
            build(left, mid, index*2+1);
            build(mid+1, right, index*2+2);
            segmentree[index] = segmentree[index*2+1] + segmentree[index*2+2];
        };
        
        build(0, n-1, 0);
    }
    
    void update(int index, int val) {
        function<void(int, int, int)> update = [&](int left, int right, int idx) -> void {
            if (left == right) {
                segmentree[idx] = val;
                return;
            }
            int mid = (right - left) / 2 + left;
            if (mid >= index)
                update(left, mid, idx*2+1);
            else
                update(mid+1, right, idx*2+2);
            segmentree[idx] = segmentree[idx*2+1] + segmentree[idx*2+2];
        };
        
        update(0, n-1, 0);
    }
    
    int sumRange(int left, int right) {
        function<int(int, int, int)> sum = [&](int rangeLeft, int rangeRight, int index) -> int {
            if (left > rangeRight || right < rangeLeft) {
                return 0;
            }
            
            if (left <= rangeLeft && right >= rangeRight) {
                return segmentree[index];
            }
            int mid = (rangeRight - rangeLeft) / 2 + rangeLeft;
            return sum(rangeLeft, mid, index*2+1) + sum(mid+1, rangeRight, index*2+2);
        };
        
        return sum(0, n-1, 0);
    }
};
