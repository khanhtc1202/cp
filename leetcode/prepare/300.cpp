/*
Problem desc: https://leetcode.com/problems/longest-increasing-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;

    BIT(): n(2e4+1) {
        bit.resize(n+1, 0);
    }
    
    int get(int p) {
        int ans = 0;
        for (; p > 0; p -= (p&-p)) {
            ans = max(ans, bit[p]);
        }
        return ans;
    }
    
    void update(int p, int val) {
        for (; p <= n; p += (p&-p)) {
            bit[p] = max(bit[p], val);
        }
    }
};

class Solution {
public:
    int lengthOfLISBIT(vector<int>& nums) {
        BIT tree;
        int ans = 1; int k = 1e4+1;
        for (int i = 0; i < nums.size(); i++) {
            int curr = tree.get(k+nums[i]-1) + 1;
            ans = max(ans, curr);
            tree.update(k+nums[i], curr);
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;

        vector<int> dp(n, 1);
        int out = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            out = max(dp[i], out);
        }

        return out;
    }
};
