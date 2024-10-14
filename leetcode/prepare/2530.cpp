/*
https://leetcode.com/problems/maximal-score-after-applying-k-operations/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> heap;
        for (auto x: nums) heap.push(x);
        while (k-- > 0) {
            int x = heap.top(); heap.pop();
            ans += x;
            heap.push(ceil(x/3.0));
        }
        return ans;
    }
};
