/*
https://leetcode.com/problems/convert-bst-to-greater-tree/
*/
#include <bits/stdc++.h>
using namespace std;

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
    TreeNode* convertBSTIterative(TreeNode* root) {
        if (!root) return root;

        TreeNode* curr = root;
        stack<TreeNode*> stk;

        auto build = [&](TreeNode* node) -> void {
            while (node) {
                stk.push(node);
                node = node->right;
            }    
        };

        build(curr);

        int currSum = 0;
        while (!stk.empty()) {
            curr = stk.top(); stk.pop();
            curr->val += currSum;
            currSum = curr->val;
            build(curr->left);
        }
        return root;
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        function<void(TreeNode*)> convert = [&](TreeNode* node) -> void {
            if (!node) return;

            convert(node->right);
            node->val += sum;
            sum = node->val;
            convert(node->left);
        };

        convert(root);
        return root;
    }
};
