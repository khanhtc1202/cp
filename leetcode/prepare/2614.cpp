/*
https://leetcode.com/problems/prime-in-diagonal/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        auto isPrime = [=](int n) -> bool {
            if (n <= 1) return false;
            for (int d = 2; d*d <= n; ++d) {
                if (n % d == 0) return false;
            }
            return true;
        };

        int ans = 0, n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (isPrime(nums[i][i])) ans = max(ans, nums[i][i]);
            if (isPrime(nums[i][n - i - 1])) ans = max(ans, nums[i][n - i - 1]);
        }
        return ans;
    }
};
