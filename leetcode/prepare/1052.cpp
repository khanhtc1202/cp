/*
https://leetcode.com/problems/grumpy-bookstore-owner/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int N = customers.size();
        int missedCustomer = 0;

        // Try to count the max possible missed customer that can be
        // realized by using the munites special power
        for (int i = 0; i < minutes; ++i) {
            missedCustomer += customers[i] * grumpy[i];
        }
        int maxMissedCustomer = missedCustomer;
        for (int i = minutes; i < N; ++i) {
            missedCustomer += customers[i] * grumpy[i];
            missedCustomer -= customers[i-minutes] * grumpy[i-minutes];

            maxMissedCustomer = max(maxMissedCustomer, missedCustomer);
        }

        // Now we have the max realizable customers (under munites)
        // We can calculate the number of max satisfied customer by counting
        // the number of "initially" satisfied customer + maxMissedCustomer
        int ans = maxMissedCustomer;
        for (int i = 0; i < N; ++i) {
            ans += customers[i] * (1 - grumpy[i]); // flip bit
        }
        return ans;
    }
};
