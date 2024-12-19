/*
https://leetcode.com/problems/max-chunks-to-make-sorted/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0, prefixSum = 0, prefixIndexSum = 0;
        for (int i = 0; i < n; ++i) {
            // curr prefix sum
            prefixSum += arr[i];
            // prefix sum of index
            prefixIndexSum += i;
            // a chunk is valid chunk if
            // prefixSum = prefixIndexSum
            if (prefixSum == prefixIndexSum)
                chunks++;
        }
        return chunks;
    }
};
