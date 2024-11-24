/*
https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        int invertCnt = 0;
        int len = (1<<n)-1; // length of Sn
        while (k > 1) {
            // if k is in the middle -> return based on inversion count
            if (k == len/2+1) {
                return invertCnt % 2 == 0 ? '1' : '0';
            }

            // if k is in the second half, invert and mirror
            if (k > len/2) {
                k = len+1-k; // mirrof position
                invertCnt++; // increment inversion count
            }
            len /= 2; // reduce length for next iteration
        }
        return invertCnt % 2 == 0 ? '0' : '1';
    }
};
