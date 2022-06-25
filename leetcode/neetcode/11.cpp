#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int ans = 0, curSize;
        while (l < r) {
            curSize = (r-l) * min(height[r], height[l]);
            ans = max(ans, curSize);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
