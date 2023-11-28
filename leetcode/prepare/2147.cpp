/*
https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
const int MOD = 1e9+7;
public:
    int numberOfWays(string corridor) {
        int seats = 0;
        int sc = 0, pc = 0;
        long res = 1;

        for (auto c: corridor) {
            if (c == 'S') {
                seats++;
                if (sc < 2) {
                    sc++;
                } else {
                    // update the number of ways
                    // by multiply (plan_count + 1)
                    (res *= (pc+1)) %= MOD;
                    // reset new block (of two seats)
                    pc = 0; sc = 1;
                }
            }
            // update the number of plans only when there are two seats
            // ignore the seats in the middle of two seats in a block
            else if(c == 'P' && sc == 2) pc++;
        }

        if (seats == 0 || seats % 2 != 0) return 0;
        return res;
    }
};
