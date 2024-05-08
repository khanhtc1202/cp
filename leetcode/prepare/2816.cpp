/*
https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}

class Solution {
public:
    static  ListNode* doubleIt(ListNode* head) {
        ListNode* prev= NULL;
        if (head->val>=5)
            head= new ListNode(0,head);
        prev=head;
        for (ListNode* curr=head; curr; prev=curr, curr=curr->next){
            if (curr->val>=5){
                prev->val++; 
                curr->val=curr->val*2-10;
            }
            else 
               curr->val*=2;
                
        }
        return head;
    }
};
