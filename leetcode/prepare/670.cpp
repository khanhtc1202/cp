/*
https://leetcode.com/problems/maximum-swap/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int N = numStr.size();
        // Store the index of the max digits in [current, end] range
        vector<int> maxRightIndex(N);
        maxRightIndex[N-1] = N-1;
        for (int i = N-2; i > -1; --i) {
            maxRightIndex[i] = (numStr[i] > numStr[maxRightIndex[i+1]]) ? i : maxRightIndex[i+1];
        }

        // Find the first place (from left) that we can swap with maximize digit from the right
        for (int i = 0; i < N; ++i) {
            if (numStr[i] < numStr[maxRightIndex[i]]) {
                swap(numStr[i], numStr[maxRightIndex[i]]);
                return stoi(numStr);
            }
        }
        return num; // No swap
    }

    int maximumSwap_MemOp(int num) {
        string numStr = to_string(num);
        int N = numStr.size();
        int swapId1 = -1, swapId2 = -1;
        int maxDigitId = -1;
        // Travel right -> left, since we need to find the biggest on the right
        for (int i = N-1; i > -1; --i) {
            if (maxDigitId == -1 || numStr[i] > numStr[maxDigitId]) {
                maxDigitId = i;
            }
            if (numStr[i] < numStr[maxDigitId]) {
                swapId1 = i;
                swapId2 = maxDigitId;
            }
        }
        if (swapId1 != -1) {
            swap(numStr[swapId1], numStr[swapId2]);
            return stoi(numStr);
        }
        return num;
    }
};
