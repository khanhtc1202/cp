/*
https://leetcode.com/problems/number-of-music-playlists/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int mod = 1e9+7;

        // dp[i][j] = how many playlist with i songs that are built by j unique songs.
        vector<vector<long>> dp(goal+1, vector<long>(n+1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= goal; ++i) {
            // if i > j, we ignore that since there would be no way
            // we can build playlist with i songs using all j unique songs.
            for (int j = 1; j <= min(i, n); ++j) {
                // The i-th song is a new song
                dp[i][j] = dp[i-1][j-1] * (n - j + 1) % mod;
                // The i-th song has played before
                if (j > k) {
                    (dp[i][j] += dp[i-1][j] * (j - k)) %= mod;
                }
            }
        }
        return dp[goal][n];
    }
};
