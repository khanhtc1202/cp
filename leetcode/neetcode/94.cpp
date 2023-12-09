/*
https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) -> void {
            if (!node) return;
            
            inorder(node->left);
            res.push_back(node->val);
            inorder(node->right);
        };
        
        inorder(root);
        return res;
    }
};
