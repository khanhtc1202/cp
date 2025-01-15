/*
https://leetcode.com/problems/minimize-xor/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int result = 0;

        auto isSet = [=](int x, int bit) -> bool {
            return x & (1 << bit);
        };

        auto setBit = [=](int& x, int bit) -> void {
            x |= (1 << bit);
        };

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = 0;
        int currentBit = 31;
        while (setBitsCount < targetSetBitsCount) {
            if (isSet(num1, currentBit) || (targetSetBitsCount - setBitsCount > currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }
            currentBit--;
        }
        return result;
    }
};
