/*
https://leetcode.com/problems/rank-transform-of-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int N = arr.size();
        vector<int> index(N);
        iota(index.begin(), index.end(), 1);
        // Sort indexies by value
        sort(index.begin(), index.end(), [&](int x, int y){
            return arr[x-1] < arr[y-1];
        });
        int prev = INT_MIN;
        for (int rank = 1, i = 0; i < N; ++i) {
            int idx = index[i];
            int x = arr[idx-1];
            if (x == prev) arr[idx-1] = arr[index[i-1]-1];
            else arr[idx-1] = rank++;
            prev = x;
        }
        return arr;
    }
};
