#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (n == 1)
            return k >= target;

        vector<int> res(target+1);
        res[0] = 0;
        for (int i = 1; i <= k; i++)
            res[i] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int x = 1; x <= k; x++) {
                    res[j] += res[j-x];
                }
            }
        }
    }
};
