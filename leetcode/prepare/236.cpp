/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor_Cond(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;

        function<bool(TreeNode*)> travel = [&](TreeNode* node) -> bool {
            if (!node) return false;

            int mid = (node == p || node == q) ? 1 : 0;
            int left = travel(node->left) ? 1 : 0;
            int right = travel(node->right) ? 1 : 0;

            if (left + right + mid >= 2) {
                ans = node;
                return true;
            }

            return (mid+left+right) > 0;
        };

        travel(root);
        return ans;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }
};
