/*
https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
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
    bitset<100001> hasN=0;
    
    ListNode* f(ListNode* curr){
        if (!curr) return NULL;
        curr->next=f(curr->next);
        if (hasN[curr->val]) curr=curr->next;
        return curr;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        for(int x: nums) hasN[x]=1;
        return f(head);
    }
};
