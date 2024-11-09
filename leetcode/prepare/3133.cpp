#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x, mask;
        --n;  // Reducing n by 1 to exclude x from the iteration

        for (mask = 1; n > 0; mask <<= 1) {
            // If the corresponding bit in x is 0
            if ((mask & x) == 0) {
                // Set the bit in result based on the least significant bit of n
                result |= (n & 1) * mask;
                // Shift n to the right by 1 to process the next bit
                n >>= 1;
            }
        }

        return result;
    }
};
