#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m;

        while (l <= r) {
            m = l + (r-l)/2;
            if (nums[m] == target) return m;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (r < 0) return 0;
        return nums[r] < target ? r + 1 : r;
    }
};

int main() {
    return 0;
}
