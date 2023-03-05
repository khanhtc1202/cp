/*
Problem desc: https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        auto reverse = [&](ListNode* start) -> pair<ListNode*, ListNode*> {
            ListNode *curr = start;
            ListNode *prev = nullptr, *next = nullptr;

            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            start->next = curr;
            return {start, prev};
        };

        ListNode *_head, *_curr, *ans = nullptr;
        _head = _curr = head;
        int cnt = 0; ListNode* prev_end = nullptr;
        while (_curr != nullptr) {
            cnt++;
            _curr = _curr->next;
            if (cnt == k) {
                auto [_end, _start] = reverse(_head);
                _head = _end->next;
                if (prev_end != nullptr) prev_end->next = _start;
                prev_end = _end;
                if (ans == nullptr) ans = _start;
                cnt = 0;
            }
        }
        return ans;
    }
};
