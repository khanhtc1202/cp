/*
https://leetcode.com/problems/split-linked-list-in-parts/
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        ListNode* curr = head;
        while (curr) {
            cnt++;
            curr = curr->next;
        }

        int sz = cnt / k;
        int extra = cnt % k;
        vector<ListNode*> ans(k, {});
        
        curr = head;
        ListNode* prev;

        for (int i = 0; i < k; ++i) {
            int iLen = sz + (extra-- > 0 ? 1 : 0);
            if (!curr) break; // stop immediately if there is no more node
            ans[i] = curr;
            prev = curr; curr = curr->next;
            while (--iLen && curr) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
        }
        return ans;
    }
};
