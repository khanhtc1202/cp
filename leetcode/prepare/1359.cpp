/*
https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = 1e9+7;
public:
    int countOrders(int n) {
        long long count = 1;
        for (int i = 2; i <= n; ++i) {
            count = (count * (2 * i - 1) * i) % MOD;
        }
        return (int)count;
    }
};
