/*
https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // dp[prev][curr] store the len of fib sequence end at arr[prev],arr[curr]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 0;
        for (int curr = 2; curr < n; ++curr) {
            int start = 0;
            int end = curr - 1;
            // scan [0, end] to find pair {arr[start], arr[end]}
            // which arr[start] + arr[end] == arr[curr]
            while (start < end) {
                int sum = arr[start]+arr[end];
                if (sum < arr[curr]) {
                    start++;
                } else if (sum > arr[curr]) {
                    end--;
                } else { // found pair
                    // update dp: extends the sequence end at arr[start],arr[end] 1
                    // since it will be ...,arr[start],arr[end],arr[curr]
                    dp[end][curr] = dp[start][end] + 1;
                    // update max
                    maxLen = max(maxLen, dp[end][curr]);
                    // keep scan for other pair since there would be
                    // longer sequence which end and arr[curr]
                    start++; end--;
                }
            }
        }
        return maxLen == 0 ? 0 : maxLen + 2;
    }
};
