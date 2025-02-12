/*
https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int sumOfDigits(int n) {
        int sum = 0;
        while (n != 0) {
            int last = n % 10;
            sum += last;
            n /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int,int> cache;

        for (auto x: nums) {
            int s = sumOfDigits(x);
            if (cache.find(s) == cache.end()) {
                cache[s] = x;
            } else {
                ans = max(ans, x+cache[s]);
                cache[s] = max(cache[s],x);
            }
        }
        return ans;
    }
};
