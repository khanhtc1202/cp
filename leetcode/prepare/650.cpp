/*
https://leetcode.com/problems/2-keys-keyboard/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        int cnt = 0, sqrtn = sqrt(n), n0 = n;
        bool isPrime = 1;
        for (int p = 2; p <= sqrtn; ++p) {
            int exp = 0;
            // check n0 is prime
            while (n0 % p == 0) {
                exp++;
                n0 /= p;
            }
            if (exp) isPrime = 0;
            cnt += exp*p; // 
        }
        if (n0 > 1) cnt += n0; // n0 is a prime
        return isPrime ? n : cnt;
    }
};
