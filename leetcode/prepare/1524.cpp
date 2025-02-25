/*
https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9+7;
        int ans = 0, sum = 0;
        int oddCount = 0, evenCount = 1;
        for (int x: arr) {
            sum += x;
            if (sum % 2 == 0) { // current sum is even
                ans += oddCount;
                evenCount++;
            } else {
                ans += evenCount;
                oddCount++;
            }
            ans %= MOD;
        }
        return ans;
    }
};
