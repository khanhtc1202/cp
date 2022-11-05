#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;

        int idx = 0, cur = 1;
        while (cur < nums.size()) {
            if (nums[cur] != nums[idx]) {
                nums[++idx] = nums[cur];
            }
            cur++;
        }
        return ++idx;
    }
};
