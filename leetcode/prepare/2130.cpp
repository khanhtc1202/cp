/*
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int sz = 1;
        ListNode* curr = head;
        while(curr->next) {
            curr = curr->next;
            sz++;
        }

        vector<int> sum(sz/2, 0);
        curr = head;
        for (int i = 0; i < sz/2; i++) {
            sum[i] = curr->val;
            curr = curr->next;
        }

        int ans = 0;
        for (int i = sz/2-1; i >= 0; i--) {
            sum[i] += curr->val;
            ans = max(ans, sum[i]);
            curr = curr->next;
        }
        return ans;
    }
};
