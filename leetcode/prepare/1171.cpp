/*
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* node = new ListNode(0, head);
        unordered_map<int, ListNode*> mp;
        int prefix = 0;
        for (ListNode* ptr=node; ptr; ptr=ptr->next) {
            prefix += (ptr->val);
            mp[prefix] = ptr;
        }
        prefix = 0;
        for (ListNode* ptr=node; ptr; ptr=ptr->next) {
            prefix += (ptr->val);
            // If the mp[prefix] exist, mean that the part between
            // current ptr and node stored as mp[prefix] has sum = 0
            // -> set next as that node's next, and eliminate the between
            ptr->next = mp[prefix]->next;
        }
        return node->next;
    }
};
