/*
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int N = s.size();
        int op = 0, carry = 0;
        for (int i = N-1; i > 0; --i) {
            if (((s[i] - '0')+carry) % 2) {
                op += 2;
                carry = 1;
            } else op++;
        }
        return op + carry;
    }
};
