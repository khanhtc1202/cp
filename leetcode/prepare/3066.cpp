/*
https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
using ll = long long;
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq(nums.begin(),nums.end());
        int ope = 0;
        while (pq.size() > 1 && pq.top() < k) {
            ll x = pq.top(); pq.pop();
            ll y = pq.top(); pq.pop();
            pq.push(x * 2 + y);
            ope++;
        }
        return ope;
    }
};
