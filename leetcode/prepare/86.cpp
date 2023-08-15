/*
https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        ListNode* smallerHead = new ListNode(0);
        ListNode* smallerTail = smallerHead;

        ListNode* greaterHead = new ListNode(0);
        ListNode* greaterTail = greaterHead;

        ListNode* curr = head;
        while (curr) {
            if (curr->val < x) {
                smallerTail->next = curr;
                smallerTail = smallerTail->next;
            } else {
                greaterTail->next = curr;
                greaterTail = greaterTail->next;
            }
            curr = curr->next;
        }

        smallerTail->next = greaterHead->next;
        greaterTail->next = nullptr;

        head = smallerHead->next;
        return head;
    }
};
