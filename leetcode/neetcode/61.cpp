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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        int cnt = 0;
        ListNode* curr = head;
        while (curr) {
            cnt++;
            curr = curr->next;
        }

        if (k % cnt == 0) return head;

        k = cnt - (k % cnt) - 1;
        curr = head;
        while (k) {
            k--;
            curr = curr->next;
        }
        ListNode *nHead = curr->next;
        curr->next = nullptr;
        curr = nHead;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = head;
        return nHead;
    }
};
