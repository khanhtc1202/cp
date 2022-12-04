#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[0] = 1;
        
        for (int i = 2; i <= n; i++) {
            // take one ele as root -> take i as root
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }

    int numTreesMath(int n) {
        long c;
        for (int i = 0; i < n; i++) {
            c = c * 2 * (2*i+1) / (i+2);
        }
        return int(c);
    }
};
