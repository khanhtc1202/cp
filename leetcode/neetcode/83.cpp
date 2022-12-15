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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode *cur = head->next, *prev = head, *toDel = nullptr;
        while (cur != nullptr) {
            if (prev->val == cur->val) {
                toDel = cur;
                prev->next = cur->next;
            } else prev = cur;

            cur = cur->next;

            if (toDel != nullptr) {
                delete toDel;
                toDel = nullptr;
            }
        }

        return head;
    }
};
