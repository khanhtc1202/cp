/*
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto middleNode = [](ListNode* node) -> ListNode* {
            ListNode *prev, *slow, *fast;
            slow = fast = node;

            while (fast != nullptr && fast->next != nullptr) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            // Cut the left side from root node.
            if (prev != nullptr) prev->next = nullptr;

            return slow;
        };

        if (head == nullptr) return nullptr;

        ListNode* middle = middleNode(head);
        TreeNode* node = new TreeNode(middle->val);

        // One node tree.
        if (head == middle) return node;

        node->left = sortedListToBST(head);
        node->right = sortedListToBST(middle->next);

        return node;
    }
};
