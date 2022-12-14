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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;

        ListNode *root, *curr, *prev, *toDel = nullptr;
        root = new ListNode();
        root->next = head;
        curr = head;
        prev = root;
        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                toDel = curr;
            } else prev = curr;

            curr = curr->next;

            if (toDel != nullptr) {
                delete toDel;
                toDel = nullptr;
            }
        }
        return root->next;
    }
};
