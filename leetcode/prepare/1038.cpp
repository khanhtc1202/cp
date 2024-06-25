/*
https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
    TreeNode* bstToGst(TreeNode* root) {
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
