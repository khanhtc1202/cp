/*
https://leetcode.com/problems/balance-a-binary-search-tree/
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        function<void(TreeNode*)> travel = [&](TreeNode* node) {
            if (!node) return;
            travel(node->left);
            inorder.push_back(node->val);
            travel(node->right);
        };

        function<TreeNode*(int, int)> build = [&](int s, int e) -> TreeNode* {
            if (s > e) return nullptr;
            
            int mid = (s+e)/2;
            TreeNode* tmp = new TreeNode(inorder[mid]);
            tmp->left = build(s, mid-1);
            tmp->right = build(mid+1, e);
            return tmp;
        };

        travel(root);
        return build(0, inorder.size()-1);
    }
};
