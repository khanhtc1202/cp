/*
https://leetcode.com/problems/remove-nodes-from-linked-list/
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
    // Monotolic stack solution, O(n) in space
    ListNode* removeNodesStk(ListNode* head) {
        ListNode dummy(INT_MAX);
        vector<ListNode*> stk;
        stk.push_back(&dummy);

        while (head) {
            while (head->val > stk.back()->val) {
                stk.pop_back();
            }
            stk.back()->next = head;
            stk.push_back(head);
            head = head->next;
        }
        return (&dummy)->next;
    }

    // In place delete with reverse treat, O(1) in space
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode* tmp = head, *prev = new ListNode(0);
        prev->next = tmp;
        int mx = tmp->val;
        while (tmp) {
            if (tmp->val < mx) {
                tmp = tmp->next;
                delete(prev->next);
                prev->next = tmp;
            } else {
                mx = tmp->val;
                prev = tmp;
                tmp = tmp->next;
            }
        }
        return reverse(head);
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = head;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
