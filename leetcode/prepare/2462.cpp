/*
https://leetcode.com/problems/total-cost-to-hire-k-workers/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> head;
        priority_queue<int, vector<int>, greater<int>> tail;
        int n = costs.size();

        for (int i = 0; i < candidates; i++) {
            head.push(costs[i]);
        }
        for (int i = max(candidates, n - candidates); i < n; i++) {
            tail.push(costs[i]);
        }

        long long ans = 0;
        int nextHead = candidates;
        int nextTail = n - 1 - candidates;

        for (int i = 0; i < k; i++) {
            if (tail.empty() || !head.empty() && head.top() <= tail.top()) {
                ans += head.top();
                head.pop();

                // Refill head if there are worker outside 2 queues
                if (nextHead <= nextTail) {
                    head.push(costs[nextHead++]);
                }
            } else { // hire from tail
                ans += tail.top();
                tail.pop();

                // Refill tail if there are worker outside 2 queues
                if (nextHead <= nextTail) {
                    tail.push(costs[nextTail--]);
                }
            }
        }
        return ans;
    }
};
