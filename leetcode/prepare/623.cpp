/*
https://leetcode.com/problems/add-one-row-to-tree/
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);

        function<void(TreeNode*, int)> travel = [&](TreeNode* node, int currDepth) -> void {
            if (node == nullptr) return;

            if (currDepth + 1 == depth) {
                // Only perform on currDepth == depth-1, no call to futher node
                TreeNode* left = node->left;
                TreeNode* right = node->right;

                node->left = new TreeNode(val);
                if (left != nullptr) node->left->left = left;

                node->right = new TreeNode(val);
                if (right != nullptr) node->right->right = right;

                return;
            }

            travel(node->left, currDepth+1);
            travel(node->right, currDepth+1);
        };

        travel(root, 1);
        return root;
    }
};
