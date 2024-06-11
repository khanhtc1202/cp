/*
https://leetcode.com/problems/relative-sort-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int bucket[1001] = {};
        for (auto x: arr1) bucket[x]++;
        int idx = 0;
        for (int i = 0; i < arr2.size(); ++i) {
            int x = arr2[i];
            while (bucket[x]-- > 0) arr1[idx++] = x;
        }
        for (int i = 0; i < 1001; ++i) {
            while (bucket[i]-- > 0) arr1[idx++] = i;
        }
        return arr1;
    }
};
