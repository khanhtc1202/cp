/*
https://leetcode.com/problems/add-two-numbers-ii/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> tmp1;
        ListNode* curr = l1;
        while (curr) {
            tmp1.push_back(curr->val);
            curr = curr->next;
        }

        vector<int> tmp2;
        curr = l2;
        while (curr) {
            tmp2.push_back(curr->val);
            curr = curr->next;
        }

        if (tmp1.size() < tmp2.size()) {
            swap(tmp1, tmp2);
        }

        ListNode* ans; curr = nullptr;
        int carry = 0;
        while (!tmp1.empty() && !tmp2.empty()) {
            int val = tmp1.back() + tmp2.back() + carry;
            carry = val / 10;
            ans = new ListNode(val % 10);
            ans->next = curr;
            curr = ans;
            tmp1.pop_back(), tmp2.pop_back();
        }

        while (!tmp1.empty()) {
            int val = tmp1.back() + carry;
            carry = val / 10;
            ans = new ListNode(val % 10);
            ans->next = curr;
            curr = ans;
            tmp1.pop_back();
        }
        if (carry) {
            ans = new ListNode(carry);
            ans->next = curr;
        }
        return ans;
    }
};
