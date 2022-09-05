#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Comparator {
    bool operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> heap;

        int sz = lists.size();
        for (int i = 0; i < sz; i++) {
            if (lists[i]) heap.push(lists[i]);
        }
        
        ListNode* ans, *curr;
        ans = curr = nullptr;
        while (!heap.empty()) {
            ListNode* nxt = heap.top(); heap.pop();
            if (!ans) {
                ans = nxt;
                curr = ans;
            } else {
                curr->next = nxt;
                curr = curr->next;
            }
            
            if (curr && curr->next) {
                heap.push(curr->next);
            }
        }
        return ans;
    }
};
