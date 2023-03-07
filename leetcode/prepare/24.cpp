/*
https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *_head = nullptr, *_prev = nullptr, *curr = head;
        while (curr && curr->next) {
            auto [_start, _end] = swap(curr);     
            
            if (!_head) _head = _start;
            if (_prev) _prev->next = _start;
            _prev = _end;

            curr = _end->next;
        }

        return _head;
    }

    pair<ListNode*, ListNode*> swap(ListNode* first) {
        ListNode* tmp = nullptr;
        ListNode* next = first->next;
        if (next->next != nullptr) tmp = next->next;

        next->next = first;
        first->next = nullptr;
        if (tmp != nullptr) first->next = tmp;
        return {next, first};
    }
};
