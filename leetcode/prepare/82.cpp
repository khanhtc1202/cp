/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return NULL;

        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;

        while(curr->next != NULL && curr->next->next != NULL){
            if(curr->next->val == curr->next->next->val){
                int num = curr->next->val;
                while(curr->next != NULL && curr->next->val == num){
                    curr->next = curr->next->next;
                }
            }
            else{
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
