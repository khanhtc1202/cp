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
    bool isPalindrome(ListNode* head) {
        bool flag = true;
        ListNode* pre = head;
        function<void(ListNode*&)> check = [&](ListNode* &cur){
            if (!cur) return;
            check(cur->next);
            if (cur->val != pre->val){
                flag = false;
                return;
            }
            pre = pre->next;
        };
        check(head);
        return flag;
    }
};
