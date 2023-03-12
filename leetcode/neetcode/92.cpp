/*
https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode *curr = head, *prev = new ListNode();
        prev->next = head;

        int cnt = 0;
        ListNode *front = nullptr, *rear = nullptr;
        while (curr && cnt < right) {
            cnt++;
            if (cnt == left-1) {
                prev = curr;
            }
            if (cnt == left) {
                front = curr;
            }
            if (cnt == right) {
                rear = curr;
            }
            curr = curr->next;
        }

        curr = front;
        ListNode* next = nullptr, *_prev = rear->next;
        for (int i = 0; i <= right - left; i++) {
            next = curr->next;
            curr->next = _prev;
            _prev = curr;
            curr = next;
        }
        prev->next = _prev;
        // In case head == front, there will be no head with hook, thus the reverse process cause lost
        // the linked between, so return _prev (new head) instead of head (with front hook)
        return left == 1 ? _prev : head;
    }
};
