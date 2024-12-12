/*
https://leetcode.com/problems/take-gifts-from-the-richest-pile/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> heap;
        for (auto x: gifts) heap.push(x);
        while (k-- > 0) {
            int tmp = floor(sqrt(heap.top()));
            heap.pop();
            heap.push(tmp);
        }
        long long ans = 0;
        while (!heap.empty()) {
            ans += heap.top();
            heap.pop();
        }
        return ans;
    }
};
