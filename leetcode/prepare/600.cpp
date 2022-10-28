#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        vector<int> digits;
        for (; n; n /= 2) {
            digits.push_back(n % 2);
        }
        reverse(digits.begin(), digits.end());
        
        int m = digits.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(2, vector<int>(2, 0)));
        
        function<int(int, int, int)> run = [&](int i, int last, int isLess) -> int {
            if (i == m) return 1;
            if (dp[i][last][isLess]) return dp[i][last][isLess];

            for (int d = 0; d <= 1 - last; d++) {
                if (isLess) {
                    dp[i][last][true] += run(i+1, d, true);
                } else if (d <= digits[i]) {
                    dp[i][last][false] += run(i+1, d, d < digits[i]);
                }
            }
            return dp[i][last][isLess];
        };
        
        return run(0,0,0);
    }
};
