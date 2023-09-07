/*
https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        ListNode* _even = head->next;
        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();

        ListNode* curr = head;
        int cnt = 0;
        while (curr) {
            if (++cnt % 2) {
                odd->next = curr;
                odd = odd->next;
                curr = curr->next;
                odd->next = nullptr;
            } else {
                even->next = curr;
                even = even->next;
                curr = curr->next;
                even->next = nullptr;
            }
        }

        // Concat odd and even lists.
        odd->next = _even;
        return head;
    }
};
