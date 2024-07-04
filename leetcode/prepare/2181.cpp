/*
https://leetcode.com/problems/merge-nodes-in-between-zeros/
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* run = head->next;
        while (run != nullptr && run->next != nullptr) {
            run = run->next;
            if (run->val == 0) {
                curr->next = run->next;
                curr = curr->next;
                run = run->next;
            } else {
                curr->val += run->val;
            }
        }
        return head->next;
    }
};
