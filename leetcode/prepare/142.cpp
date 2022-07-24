#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                break;
        }

        if (fast != slow)
            return nullptr;

        ListNode *slow2 = head;
        while (slow != slow2) {
            slow = slow->next;
            slow2 = slow2->next;
        }
        return slow;
    }
};
